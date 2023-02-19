/****************************** type - int ********************************/
template <int N>
struct int_ {
    static constexpr int value = N;
    using value_type = int;
    using type = int_;
    constexpr operator int() const { return value; }
    constexpr value_type operator()() { return value; }
};
/**************************************************************************/

/****************************** type - bool *******************************/
template <bool B>
struct bool_ {
    static constexpr bool value = B;
    using value_type = bool;
    using type = bool_;
    constexpr operator bool() { return value; }
    constexpr value_type operator()() { return value; }
};
/**************************************************************************/

/**************************** check - is_reference ************************/
template <typename T>
struct is_reference_ : bool_<false> { };

template <typename T>
struct is_reference_<T&> : bool_<true> { };

template <typename T>
struct is_reference_<T&&> : bool_<true> { };
/**************************************************************************/

/**************************** check - is_same *****************************/
template <typename T, typename U>
struct is_same_ : bool_<false> { };

template <typename T>
struct is_same_<T, T> : bool_<true> { };
/**************************************************************************/

/**************************** check - is_one_of ***************************/
template <typename T, typename U, typename... Args>
struct is_one_of_ {
    static constexpr bool value = is_one_of_<T, U>::value || is_one_of_<T, Args...>::value;
};

template <typename T, typename U>
struct is_one_of_<T, U> : is_same_<T, U> { };
/**************************************************************************/

/************************* check - is_instantation ************************/
template <typename Inst, template <typename...> typename Tmpl>
struct is_instantiation_of : bool_<false> { };

template <template <typename...> typename Tmpl, typename... Args>
struct is_instantiation_of<Tmpl<Args...>, Tmpl> : bool_<true> { };
/**************************************************************************/

/************************* num - count_dimension **************************/
template <typename T>
struct count_dimension {
    static constexpr int value = 0;
};

template <typename T>
struct count_dimension<T[]> {
    static constexpr int value = count_dimension<T>::value + 1;
};

template <typename T, int N>
struct count_dimension<T[N]> {
    static constexpr int value = count_dimension<T>::value + 1;
};
/**************************************************************************/

#include <iostream>
#include <vector>
int main(void)
{
    // int_<10> t_int;
    // auto& rt_int = t_int;
    // std::cout << is_reference_<decltype(rt_int)>()();

    // std::cout << is_one_of_<int, float>::value;

    // std::vector<int> vec;
    // std::cout << is_instantiation_of<decltype(vec), std::vector>::value;

    // int arr3[2][3][4];
    // std::cout << count_dimension<decltype(arr3)>::value;
}