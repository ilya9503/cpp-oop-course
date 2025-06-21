#include <iostream>

// здесь объявляйте функцию
template <typename AR> AR ar_sum_positive(AR* arr, size_t len)
{
    AR sum{0};

    for(size_t i=0; i < len; ++i)
        if(arr[i] > 0)
            sum += arr[i];

    return sum;
}

int main()
{
    // здесь продолжайте функцию main
    float d1[] = {0.1f, 2.4f, 1.5f, -0.3f, 1.0f, -11.5f};
    double d2[] = {-4.3, 0.8, 15.3, -0.01, -1.2, -6.5};
    int d3[] = {6, 4, -1, -3, 0, 10, 8, -1, 2};

    float s1 = ar_sum_positive(d1, sizeof(d1)/sizeof(*d1));
    double s2 = ar_sum_positive(d2, sizeof(d2)/sizeof(*d2));
    int s3 = ar_sum_positive(d3, sizeof(d3)/sizeof(*d3));

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}