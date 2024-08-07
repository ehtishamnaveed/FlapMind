#include "../Header/Chart.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Initialization method
void Chart::initialize(const std::string& filename) {
    data = readCSV(filename);
    if (data.empty()) {
        std::cerr << "No data available to visualize." << std::endl;
        throw std::runtime_error("No data available to visualize.");
    }

    // Load font for text rendering
    if (!font.loadFromFile("Resources/Font/ChartFont.ttf")) { // Ensure you have a valid font file
        std::cerr << "Failed to load font" << std::endl;
        throw std::runtime_error("Failed to load font.");
    }

    // Determine maximum score for y-axis scaling
    unsigned short maxScore = 0;
    for (const auto& point : data) {
        if (point.score > maxScore) {
            maxScore = point.score;
        }
    }

    // Calculate scale factors for x and y axes
    xScale = static_cast<float>(windowWidth - 100) / (data.back().generationNo - data.front().generationNo);
    yScale = static_cast<float>(windowHeight - 100) / maxScore; // Adjust scale based on max score

    // Set up the line chart as a SFML lines strip
    lineChart.setPrimitiveType(sf::LinesStrip);
    for (const auto& point : data) {
        float x = 50 + (point.generationNo - data.front().generationNo) * xScale;
        float y = windowHeight - 50 - (point.score * yScale); // Invert Y-axis
        lineChart.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Green));
    }
}

// Runs the main rendering loop for the chart
void Chart::draw() {
    sf::CircleShape pointShape(4); // Shape for data points
    pointShape.setFillColor(sf::Color::Red); // Set the color for data points

    // while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             window.close(); // Close the window when the close event is triggered
    //     }

        window.clear(sf::Color::White); // Clear the window with a white background

        // Draw grid, axis lines, and chart
        drawGrid();
        drawAxisLines();
        window.draw(lineChart);

        // Draw plotting points
        for (const auto& point : data) {
            float x = 50 + (point.generationNo - data.front().generationNo) * xScale;
            float y = windowHeight - 50 - (point.score * yScale); // Invert Y-axis
            pointShape.setPosition(x - pointShape.getRadius(), y - pointShape.getRadius());
            window.draw(pointShape);
        }

        // Draw axis labels and titles
        drawAxisLabels();
        drawTitles();

        window.display(); // Display the rendered frame
    // }
}


void Chart::reset() {
    data.clear();
    lineChart.clear();
    // Other reset operations
}


// Reads data from a CSV file
std::vector<DataPoint> Chart::readCSV(const std::string& filename) {
    std::vector<DataPoint> data;
    std::ifstream file(filename);
    std::string line;

    // Skip the header
    std::getline(file, line);

    // Read the data from each line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string temp;
        DataPoint point;

        std::getline(ss, temp, ',');
        point.generationNo = static_cast<unsigned short>(std::stoi(temp));
        std::getline(ss, temp, ',');
        point.score = static_cast<unsigned short>(std::stoi(temp));

        data.push_back(point);
    }

    return data;
}

// Draws the grid lines on the chart
void Chart::drawGrid() {
    sf::Color gridColor(230, 230, 230); // Light gray color for grid lines

    // Draw vertical grid lines
    for (unsigned int x = 50; x < windowWidth - 50; x += 50) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(static_cast<float>(x), 50), gridColor),
            sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(windowHeight - 50)), gridColor)
        };
        window.draw(line, 2, sf::Lines);
    }

    // Draw horizontal grid lines
    for (unsigned int y = 50; y < windowHeight - 50; y += 50) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(50, static_cast<float>(y)), gridColor),
            sf::Vertex(sf::Vector2f(static_cast<float>(windowWidth - 50), static_cast<float>(y)), gridColor)
        };
        window.draw(line, 2, sf::Lines);
    }
}

// Draws the X and Y axis lines
void Chart::drawAxisLines() {
    // X-axis
    sf::Vertex xAxis[] = {
        sf::Vertex(sf::Vector2f(50, windowHeight - 50), sf::Color::Black),
        sf::Vertex(sf::Vector2f(windowWidth - 50, windowHeight - 50), sf::Color::Black)
    };
    window.draw(xAxis, 2, sf::Lines);

    // Y-axis
    sf::Vertex yAxis[] = {
        sf::Vertex(sf::Vector2f(50, 50), sf::Color::Black),
        sf::Vertex(sf::Vector2f(50, windowHeight - 50), sf::Color::Black)
    };
    window.draw(yAxis, 2, sf::Lines);
}

// Draws the axis labels and grid labels
void Chart::drawAxisLabels() {
    // X-axis labels (generation numbers)
    for (const auto& point : data) {
        std::string label = std::to_string(point.generationNo);
        float x = 50 + (point.generationNo - data.front().generationNo) * xScale;
        drawText(label, sf::Vector2f(x - 10, windowHeight - 40), 12, sf::Color::Black); // Adjusted position
    }

    // Y-axis labels (score values)
    unsigned short maxScore = 0;
    for (const auto& point : data) {
        if (point.score > maxScore) {
            maxScore = point.score;
        }
    }

    int step = maxScore / 5;
    step = (step == 0) ? 1 : step; // Ensure step is at least 1
    
    // Draw labels for the Y-axis
    for (int i = 0; i <= 10; ++i) {
        int scoreValue = i * step;
        if (scoreValue > maxScore) {
            scoreValue = maxScore; // Ensure the last label does not exceed the maxScore
        }
        std::string label = std::to_string(scoreValue);
        float y = windowHeight - 50 - (scoreValue * yScale);
        drawText(label, sf::Vector2f(20, y - 10), 12, sf::Color::Black); // Adjusted position to fit within the window frame
    }
}

// Draws text vertically (used for the Y-axis title)
void Chart::drawTextVertically(const std::string& text, const sf::Vector2f& position, unsigned int size, sf::Color color) {
    sf::Text sfText(text, font, size);
    sfText.setFillColor(color);
    sfText.setPosition(position);

    // Rotate text vertically
    sfText.setRotation(90);
    window.draw(sfText);
}

// Draws the chart and axis titles
void Chart::drawTitles() {
    // Draw X-axis title
    drawText("Generation", sf::Vector2f(windowWidth / 2.0f - 60, windowHeight - 20), 16, sf::Color::Black);

    // Draw Y-axis title "Score" vertically
    drawTextVertically("Score", sf::Vector2f(20, windowHeight / 2.0f - 30), 16, sf::Color::Black); // Adjusted position

    // Draw chart title
    drawText("Score vs Generation", sf::Vector2f(windowWidth / 2.0f - 100, 10), 20, sf::Color::Black); // Adjusted position
}

// Draws a text string at a specified position
void Chart::drawText(const std::string& text, const sf::Vector2f& position, unsigned int size, sf::Color color) {
    sf::Text sfText(text, font, size);
    sfText.setFillColor(color);
    sfText.setPosition(position);
    window.draw(sfText);
}
