#include <QCoreApplication>
#include "inifile.h"
int main(int argc, char *argv[])
{

    void* handle = openIniFile("/home/cj/workspace/test.ini", false);
    if (!handle)
        return -1;
    WriteProfileDouble("double", "aaa", 123.4567, handle);
    WriteProfileFloat("float", "b", -1e-5, handle);
    nfRectF rect; rect.l = 1; rect.t=2; rect.r=3;rect.b = 4;
    WriteProfileRectFloat("Rect", "c", &rect, handle);
    int bb[3] = {1,2,3};
    WriteProfileArrayInt("Aray", "a", bb,3, handle);
    WriteProfileInt("Number", "y", 11111, handle);
    WriteProfileInt("Number", "z", 1234560007, handle);

    char data[256];
    double dd = GetProfileDouble("double", "aaa",0, handle);
    printf("double dd=%f\n", dd);
    GetProfileString("Sting", "aaaaaa", data, sizeof(data), "xxxx", handle);
    printf("Sting aaaaaaa=%s\n", data);
    GetProfileString("String", "b", data, sizeof(data), "xxxx", handle);
    printf("Sting b=%s\n", data);
    GetProfileString("Sting", "aaa", data, sizeof(data), "xxxx", handle);
    printf("Sting aaa=%s\n", data);

    int x = GetProfileInt("Number", "x", -1, handle);
    int y = GetProfileInt("Numberyyyy", "y", -1, handle);
    int z = GetProfileInt("Number", "z", -1, handle);
    printf ("Number = %d %d %d\n", x,y,z);

    saveAsIniFile(handle, "/home/cj/workspace/test2.ini");

    WriteProfileString("Sting", "warning", "again, this line is not in test2.ini", handle);

    closeIniFile(handle);

}
