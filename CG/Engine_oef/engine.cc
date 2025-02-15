#include "easy_image.h"
#include "ini_configuration.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

std::vector<int> scaleColor(const std::vector<double>& color) {
        std::vector<int> scaledColor(3);
        for (int i = 0; i < 3; ++i) {
                scaledColor[i] = static_cast<int>(color[i] * 255);
        }
        return scaledColor;
}

img::EasyImage generateColorRectangle(int width,int height) {
        img::EasyImage image(width, height);
        for(unsigned int i = 0; i < width; i++)
        {
                for(unsigned int j = 0; j < height; j++)
                {
                        image(i,j).red = i;
                        image(i,j).green = j;
                        image(i,j).blue = (i+j)%256;
                }
        }
        return image;
}

img::EasyImage generateBlocks(int width, int height, int nrXBlocks, int nrYBlocks, std::vector<double> colorWhite, std::vector<double> colorBlack, bool invertColors) {
        std::vector<int> scaledWhite = scaleColor(colorWhite);
        std::vector<int> scaledBlack = scaleColor(colorBlack);

        int Wb = width/nrXBlocks;
        int Hb = height/nrYBlocks;
        img::EasyImage image(width, height);
        for (int px = 0; px < width; px++ ) {
                for (int py = 0; py < height; py++) {
                        int Bx = std::floor(px/Wb);
                        int By = std::floor(py/Hb);

                        bool isWhite = (Bx + By) % 2 == 0;

                        if (invertColors) {
                                isWhite = !isWhite;
                        }

                        if (isWhite) {
                                image(px,py) = img::Color(scaledWhite[0], scaledWhite[1], scaledWhite[2]);
                        } else {
                                image(px,py)= img::Color(scaledBlack[0],scaledBlack[1], scaledBlack[2]);
                        }
                }
        }
        return image;
}

img::EasyImage generate_image(const ini::Configuration &configuration)
{
        std::string type = configuration["General"]["type"].as_string_or_die();

        int width = configuration["ImageProperties"]["width"];
        int height = configuration["ImageProperties"]["height"];
        if (type == "IntroColorRectangle") {
                return generateColorRectangle(width, height);
        }

        if (type == "IntroBlocks") {
                int nrXBlocks = configuration["BlockProperties"]["nrXBlocks"];
                int nrYBlocks = configuration["BlockProperties"]["nrYBlocks"];

                std::vector<double> colorWhite = configuration["BlockProperties"]["colorWhite"];
                std::vector<double> colorBlack = configuration["BlockProperties"]["colorBlack"];
                bool invertColors = configuration["BlockProperties"]["invertColors"];
                return generateBlocks(width, height, nrXBlocks, nrYBlocks, colorWhite, colorBlack, invertColors);
        }
	return img::EasyImage();
}

int main(int argc, char const* argv[])
{
        int retVal = 0;
        try
        {
                std::vector<std::string> args = std::vector<std::string>(argv+1, argv+argc);
                if (args.empty()) {
                        std::ifstream fileIn("filelist");
                        std::string filelistName;
                        while (std::getline(fileIn, filelistName)) {
                                args.push_back(filelistName);
                        }
                }
                for(std::string fileName : args)
                {
                        ini::Configuration conf;
                        try
                        {
                                std::ifstream fin(fileName);
                                if (fin.peek() == std::istream::traits_type::eof()) {
                                    std::cout << "Ini file appears empty. Does '" <<
                                    fileName << "' exist?" << std::endl;
                                    continue;
                                }
                                fin >> conf;
                                fin.close();
                        }
                        catch(ini::ParseException& ex)
                        {
                                std::cerr << "Error parsing file: " << fileName << ": " << ex.what() << std::endl;
                                retVal = 1;
                                continue;
                        }

                        img::EasyImage image = generate_image(conf);
                        if(image.get_height() > 0 && image.get_width() > 0)
                        {
                                std::string::size_type pos = fileName.rfind('.');
                                if(pos == std::string::npos)
                                {
                                        //filename does not contain a '.' --> append a '.bmp' suffix
                                        fileName += ".bmp";
                                }
                                else
                                {
                                        fileName = fileName.substr(0,pos) + ".bmp";
                                }
                                try
                                {
                                        std::ofstream f_out(fileName.c_str(),std::ios::trunc | std::ios::out | std::ios::binary);
                                        f_out << image;

                                }
                                catch(std::exception& ex)
                                {
                                        std::cerr << "Failed to write image to file: " << ex.what() << std::endl;
                                        retVal = 1;
                                }
                        }
                        else
                        {
                                std::cout << "Could not generate image for " << fileName << std::endl;
                        }
                }
        }
        catch(const std::bad_alloc &exception)
        {
    		//When you run out of memory this exception is thrown. When this happens the return value of the program MUST be '100'.
    		//Basically this return value tells our automated test scripts to run your engine on a pc with more memory.
    		//(Unless of course you are already consuming the maximum allowed amount of memory)
    		//If your engine does NOT adhere to this requirement you risk losing points because then our scripts will
		//mark the test as failed while in reality it just needed a bit more memory
                std::cerr << "Error: insufficient memory" << std::endl;
                retVal = 100;
        }
        return retVal;
}
