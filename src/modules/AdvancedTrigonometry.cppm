module;
export module AdvancedTrigonometry;
import std;


namespace AdvancedTrigonometry
{

export template <typename T>
requires std::is_arithmetic_v<T>
T sum(const T a, const T b)
{
    return a + b;
}

}
