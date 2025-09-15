import std;
import AdvancedTrigonometry;


int main()
{
    const int a = 3;
    const int b = 4;
    const auto result = AdvancedTrigonometry::sum(a, b);
    std::println("summing {} and {}: {}", a, b, result);

    const auto resultDouble = AdvancedTrigonometry::sum(1.5231, 40.5678);
    std::println("summing doubles: {}", resultDouble);

    // uncommenting this should give you a:
    // error: no matching function for call to 'sum'
    // note: candidate template ignored: constraints not satisfied [with T = std::string]
    // const std::string strA = "strA";
    // const std::string strB = "strB";
    // std::println("summing strings: {}", AdvancedTrigonometry::sum(strA, strB));

    return 0;
}
