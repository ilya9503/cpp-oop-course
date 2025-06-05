#include <iostream>

class FileData {};
int a;
long b;
double *ptr_d = new double;

double& lnk_ptr = *ptr_d;
int&& lnk_r_b = 10 + b;
int&& lnk_r_ab = a + b + 8;
const FileData& lnk_fd = FileData();
FileData&& lnk_r_fd = FileData();


lnk_r_fd = lnk_fd;

int& lnk_res = static_cast<int&>(lnk_r_ab);

double&& lnk_r_res = std::move(lnk_ptr);

lnk_r_b = lnk_r_ab;

double&& lnk_r_res = static_cast<double&&>(lnk_ptr);

double&& lnk_r_ptr = lnk_ptr;