#if 0
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

        if (type == "IntroLines") {
                std::string figure = configuration["LineProperties"]["figure"];

                int nrLines = configuration["LineProperties"]["nrLines"];
                std::vector<double> lineColor = configuration["LineProperties"]["lineColor"];
                std::vector<double> backgroundColor = configuration["LineProperties"]["backgroundcolor"];

                if (figure == "QuarterCircle") {
                        return QuarterCircle(height,width,nrLines,lineColor,backgroundColor);
                } if (figure == "Eye") {
                        return Eye(height,width,nrLines,lineColor,backgroundColor);
                } if (figure == "Diamond") {
                        return Diamond(height,width,nrLines,lineColor,backgroundColor);
                }
        }
        return img::EasyImage();
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

img::EasyImage QuarterCircle(int height, int width, int nrLines, std::vector<double> lineColor, std::vector<double> backgroundColor) {
       img::EasyImage image(width,height);

        // background coloring
        std::vector<int> scaledBgColor = scaleColor(backgroundColor);
        std::vector<int> scaledLineColor = scaleColor(lineColor);
        // for (int px=0; px<width; px++) {
        //         for (int py=0; py<height; py++) {
        //                 image(px,py) = img::Color(scaledBgColor[0], scaledBgColor[1],scaledBgColor[2]);
        //         }
        // }
        img::Color bg(scaledBgColor[0], scaledBgColor[1], scaledBgColor[2]);
        img::Color line(scaledLineColor[0], scaledLineColor[1], scaledLineColor[2]);
        image.clear(bg);

        double Hs = (height-1.0)/(nrLines-1);
        double Ws = (width-1.0)/(nrLines-1);
        // drawing lines
        for (int i = 0; i < nrLines; ++i) {
                int x_end = std::lround(i*Ws);
                int y_start = std::lround(i*Hs);

                x_end = std::max(0, std::min(x_end, width - 1));
                y_start = std::max(0, std::min(y_start, height - 1));

                image.draw_line(
                        0,
                        y_start,
                        x_end,
                        height-1,
                        line
                        );
        }
        return image;
}

img::EasyImage Eye(int height, int width, int nrLines, std::vector<double> lineColor, std::vector<double> backgroundColor) {
        img::EasyImage image(width,height);
        std::vector<int> scaledBgColor = scaleColor(backgroundColor);
        std::vector<int> scaledLineColor = scaleColor(lineColor);
        img::Color bg(scaledBgColor[0], scaledBgColor[1], scaledBgColor[2]);
        img::Color line(scaledLineColor[0], scaledLineColor[1], scaledLineColor[2]);
        image.clear(bg);

        double Hs = (height-1.0)/(nrLines-1);
        double Ws = (width-1.0)/(nrLines-1);

        for (int i = 0; i < nrLines; ++i) {
                int x_end = std::lround(i*Ws);
                int y_start = std::lround(i*Hs);

                x_end = std::max(0, std::min(x_end, width - 1));
                y_start = std::max(0, std::min(y_start, height - 1));

                image.draw_line(0, y_start, x_end, height-1, line);
                image.draw_line(width-1, y_start, x_end, 0, line);
        }
        return image;
}

img::EasyImage Diamond(int height, int width, int nrLines, std::vector<double> lineColor, std::vector<double> backgroundColor) {
        img::EasyImage image(width,height);
        double Hs = (height-1.0)/(nrLines-1);
        double Ws = (width-1.0)/(nrLines-1);

        std::vector<int> scaledLine = scaleColor(lineColor);
        img::Color scaledLineColor(scaledLine[0],scaledLine[1], scaledLine[2]);

        for (int i = 0; i < nrLines; ++i) {
                int x_end = std::lround(i*Ws);
                int y_start = std::lround(i*Hs);
                x_end = std::max(0, std::min(x_end, width - 1));
                y_start = std::max(0, std::min(y_start, height - 1));

                //bottom left
                image.draw_line((width/2)-1, y_start/2, (width/2)-1-(x_end/2),(height/2)-1,scaledLineColor);

                image.draw_line((width/2)-1, (height/2)-1+(y_start/2), (x_end/2),(height/2)-1,scaledLineColor);

                //top left
                image.draw_line((width/2)-1, (height/2)-1+(y_start/2), (x_end/2),(height/2)-1,scaledLineColor);


        }
        return image;

}
#endif 0