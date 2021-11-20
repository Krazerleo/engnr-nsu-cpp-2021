#include "./inc/Hasher.h"

#include <iostream>
#include <string>
#include <vector>

void HelpPrint()
{
    std::cout << "-h, --help                       ==== Help message" << std::endl;
    std::cout << "-m, --mode                       ==== Choose Hash Mode" << std::endl;
    std::cout << "-f, --file                       ==== Filepath" << std::endl;
    return;
}

void ErrHelpPrint()
{
    std::cerr << "-h, --help                       ==== Help message" << std::endl;
    std::cerr << "-m, --mode                       ==== Choose Hash Mode" << std::endl;
    std::cerr << "-f, --file                       ==== Filepath" << std::endl;
    return;
}

int main(int argc, char *argv[])
{
    std::vector<std::string*> tokens; 
    tokens.push_back(new std::string("./Lab_1"));
    tokens.push_back(new std::string("../../../Desktop/tests/test_4bytes/file"));
    tokens.push_back(new std::string("-m"));
    tokens.push_back(new std::string("sum64"));
    HashMode h;
   // for (int i=0; i < argc; i++)
   //     tokens.push_back(new std::string(argv[i]));

    if (tokens.size() == 1) 
    {
        std::cerr << "No parameters" << std::endl;
        ErrHelpPrint();
        return -1;
    }

    if ((*tokens[1]) == "-h" || *(tokens[1]) == "--help")
    {
        if (tokens.size() > 2) 
        {
            ErrHelpPrint();
            return -1;
        }
        HelpPrint();
        return 0;
    }
    
    if (tokens.size() == 2 || tokens.size() == 3)
    {
        std::cerr << "Few Arguements" << std::endl;
        ErrHelpPrint();
        return -1;
    }

    if ((*(tokens[1]) == "-m" || *(tokens[1]) == "--mode") && tokens.size( ) == 4)
    {
        if (*tokens[2] == "adler32") h = HashMode::_Adler32;
        if (*tokens[2] == "sum64") h = HashMode::_Hash64;

        if (h == HashMode::_WRONG) 
        {
            std::cerr << "Wrong hash mode" << std::endl;
            ErrHelpPrint();
            return -1;
        }
        Status s;
        s = hashProccessing(argv[3], h);
        return s == Status::_SUCCESS ?  0 :  -1;
    }
    else if ((*(tokens[2]) == "-m" || *(tokens[2]) == "--mode") && tokens.size( ) == 4)
    {
        if (*tokens[3] == "adler32") h = HashMode::_Adler32;
        if (*tokens[3] == "sum64") h = HashMode::_Hash64;

        if (h == HashMode::_WRONG) 
        {
            std::cerr << "Wrong hash mode" << std::endl;
            ErrHelpPrint();
            return -1;
        }
        Status s;
        s = hashProccessing((*tokens[1]).c_str(), h);
        return s == Status::_SUCCESS ?  0 :  -1;
    }
    else
    {
        std::cerr << "Incorrect Input" << std::endl;
        ErrHelpPrint();
        return -1;
    }
}
