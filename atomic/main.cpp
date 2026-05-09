#include <format>
#include <fstream>
#include <mutex>
#include <print>
#include <random>
#include <shared_mutex>
#include <thread>
#include <chrono>

std::mutex mtio;
std::shared_mutex reader_writer;

std::string array[] = {"hello", "world", "jabibi"};

std::random_device rd;
std::mt19937 genw(rd());
std::uniform_int_distribution dis(0, 2);

std::string random_word() {
    int a = dis(genw);
    return array[a];
}

void task(int i) {
    {
        std::unique_lock<std::mutex> lock(mtio);
        std::println("iniciando la task {}", i);
    }

    std::ofstream file("test.txt", std::ios::app);

    while (true) {
        {
            std::unique_lock<std::shared_mutex> writer_lock(reader_writer);
            file << random_word() << '\n';
            file.flush();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void leer(int id) {
    while (true) {
        {
            std::shared_lock<std::shared_mutex> reader_lock(reader_writer);
            std::ifstream file("test.txt");
            std::string line;
            while (std::getline(file, line)) {
                std::unique_lock<std::mutex> lock(mtio);
                std::println("[lector {}] {}", id, line);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {
    std::println("hello world!");

    std::thread t1(task, 1);
    std::thread t2(leer, 2);
    std::thread t3(leer, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

