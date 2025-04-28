#include <iostream>
#include <string>
#include <sstream>  // std::stringstream

void BubbleSort(int* arr, int size);

class ExtensionFilter {
    std::string ext_str;    // строка с расширениями, которые выделяем из списка файлов
public:
    ExtensionFilter(std::string ext) : ext_str(ext)
        {   }
    /*
        lst - массив с файлами;
        size_lst - длина массива lst (число элементов);
        flt_lst - массив с результатом фильтрации;
        max_count_files - максимальный размер массива flt_lst
    */
    int operator()(const std::string* lst, size_t size_lst, std::string* flt_lst, int max_count_files)
    {
        std::stringstream ss(ext_str);  // создаем поток со строкой ext_str. Аналогично std::cin
        std::string temp;               // сюда считываем расширения по очереди
        int counter{0};
        int indexes[max_count_files]{0};  // массив индексов отфильтрованных строк

        while(std::getline(ss, temp, '|')) {    // считываем подстроку до символа '|'
            for(int i = 0; i < size_lst; ++i){
                if(counter < max_count_files && lst[i].find(temp) != std::string::npos) {
                    indexes[counter++] = i; // записываем отфильтрованный индекс
                }
            }
        }

        BubbleSort(indexes, counter);   // сортируем индексы по возрастанию

        for(int i = 0; i < counter; ++i){
            flt_lst[i] = lst[indexes[i]];
        }

        return counter;
    }
};

void BubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Меняем местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }    
}

int main()
{
    ExtensionFilter image_flt("docx|zip|gif");

    enum { max_count_files = 100 };
    std::string lst[] = {"jim.jpg", "net.avi", "out1.png", "rep1.gif", "text.docx", "ava.8.jpg", "it.gif", "test.tiff", "arch.zip"};
    std::string flt_lst[max_count_files];
    int count = image_flt(lst, std::size(lst), flt_lst, max_count_files);
    std::cout << count << std::endl;
    for(int i = 0; i < count; ++i)
        std::cout << flt_lst[i] << std::endl;

    return 0;
}