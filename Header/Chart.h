#ifndef CHART_H
#define CHART_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Structure to hold data points for the chart
struct DataPoint {
    unsigned short generationNo; // Generation number
    unsigned short score;        // Score associated with the generation
};

// Class to handle the creation and rendering of the chart
class Chart {
public:
    // Constructor
    Chart() {
        // SFML window setup
        window.create(sf::VideoMode(windowWidth, windowHeight), "Line Chart Visualizer");
        // drawText("Chart will appear after", sf::Vector2f(windowWidth / 2.0f - 100, 10), 20, sf::Color::Black);
    }

    // initializes the chart with data from a CSV file
    void initialize(const std::string& filename);

    // Destructor
    ~Chart() {
        // Cleanup if necessary
        if (window.isOpen()) {
            window.close();  // Ensure the window is closed
        }
    }

    // Runs the chart rendering loop
    void draw();

    void reset();

private:
    sf::RenderWindow window; 
    sf::Font font;             // SFML font for text rendering
    sf::VertexArray lineChart; // SFML vertex array to hold line chart points
    std::vector<DataPoint> data; // Vector to store data points

    float xScale;  // Scale factor for the X-axis
    float yScale;  // Scale factor for the Y-axis

    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 600;

    // Reads data from a CSV file
    std::vector<DataPoint> readCSV(const std::string& filename);

    // Draws the grid on the chart
    void drawGrid();

    // Draws the X and Y axis lines
    void drawAxisLines();

    // Draws the axis labels and grid labels
    void drawAxisLabels();

    // Draws text vertically (used for Y-axis title)
    void drawTextVertically(const std::string& text, const sf::Vector2f& position, unsigned int size, sf::Color color);

    // Draws the chart and axis titles
    void drawTitles();

    // Draws a text string at a specified position
    void drawText(const std::string& text, const sf::Vector2f& position, unsigned int size, sf::Color color);
};

#endif
