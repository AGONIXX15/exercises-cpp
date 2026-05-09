#include <concepts>
#include <algorithm>
import <iostream>;


template<class T>
concept C = requires(T a, T b, const T c, const T d)
{
    c == d;           // expression #1: does not modify the operands
    a = std::move(b); // expression #2: modifies both operands
    a = c;            // expression #3: modifies the left operand `a`
};
 
// Expression #1 implicitly requires additional expression variations that
// meet the requirements for c == d (including non-modification),
// as if the following expressions had been declared as well:
 
// ------ const == const ------- ------ const == non-const ---
//                                         c  ==           b;
//            c == std::move(d);           c  == std::move(b);
// std::move(c) ==           d;  std::move(c) ==           b;
// std::move(c) == std::move(d); std::move(c) == std::move(b);
 
// -- non-const == const ------- -- non-const == non-const ---
//           a  ==           d;            a  ==           b;
//           a  == std::move(d);           a  == std::move(b);
// std::move(a) ==           d;  std::move(a) ==           b;
// std::move(a) == std::move(d); std::move(a) == std::move(b);
 
// Expression #3 implicitly requires additional expression variations that
// meet the requirements for a = c
// (including non-modification of the second operand),
// as if the expressions a = b (non-constant lvalue variation)
// and a = std::move(c) (const rvalue variation) had been declared.
 
// Note: Since expression #2 already requires the non-constant rvalue variation
// (a == std::move(b)) explicitly, expression #3 does not implicitly require it anymore.
 
// The type T meets the explicitly stated syntactic requirements of
// concept C above, but does not meet the additional implicit requirements
// (i.e., T satisfies but does not model C):
// a program requires C<T> is ill-formed (no diagnostic required).
struct T
{
    bool operator==(const T&) const { return true; }
    bool operator==(T&) = delete;
};





int main() {
   return 0;
}
