/* Minimal main program -- everything is loaded from the library */

#include "Python.h"
#include "pycore_pylifecycle.h"

#ifdef MS_WINDOWS
int
wmain(int argc, wchar_t **argv)
{
    printf("\n�ڵ��ö�ջ������������������ǳ������� �� longobject 311 �� ���϶ϵ�  \n");
    return Py_Main(argc, argv);
}
#else
int
main(int argc, char **argv)
{
    //printf("\n ������main  ---��\n ");
    return Py_BytesMain(argc, argv);
}
#endif
