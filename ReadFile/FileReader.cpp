#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio>

using namespace std;

class FileReader {

private:
    map<u32, map<u32, string>> f_stringMap;
public:
    FileReader(char *filePath = "") {
        FILE *pFile = fopen(filePath, "r"); // 打开文件
        if (pFile == NULL) {
            return -1;
        }
        // fseek把fp文件读写指针移到指定位置
        fseek(pFile, 0, SEEK_END);
        // ftell获取文件的当前读写位置
        // uSize就是文件的长度
        u32 uSize = ftell(pFile);
        // rewind将文件内部的指针重新指向一个流的开头
        rewind(pFile);

        char *fileBuffer = new char[uSize];
        fread(fileBuffer, 1, uSize, pFile);
        map<u32, string> stringMap;
        u32 uiIndex = 1;
        char *pBegin = fileBuffer;
        char *pEnd = strchr(pBegin, '\n');

        pBegin = pEnd + 1;
        pEnd = strchr(pBegin, '\n');
        while(pEnd) {
            string strTemp;
            strTemp.insert(0, pBegin, pEnd - pBegin);
            assert(!strTemp.empty());
            stringMap[uiIndex ++] = strTemp;
            pBegin = pEnd + 1;
            pEnd = strchr(pBegin, '\n');
        }
        delete []fileBuffer;
        fileBuffer = NULL;
        pBegin = NULL;
        pEnd = NULL;

        map<u32, string>::iterator iter = stringMap.begin();
        for (; iter != stringMap.end(); ++iter) {
            vector<string> stringVec;
            map<u32, string> stringMapTemp;
            assert(GetParamFromString(iter->second, stringVec) > 0);

            vector<string>::size_type idx = 0;
            for (; i != stringVec.size(); ++idx) {
                stringMapTemp[idx + 1] = stringVec[idx];
                f_stringMap[iter->first] = stringMapTemp;
            }
        }
        fclose(pFile);
    }
}
