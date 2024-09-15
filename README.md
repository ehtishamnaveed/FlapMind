# FlapMind
Game Development and Neural Network

## Project Overview
- FlapMind is a desktop game designed for Windows, developed in C++. Inspired by the classic Flappy Bird, this project reimagines the game with modern features such as multiple game modes and customizable themes.
- It not only revitalizes a classic game with new functionalities but also offers a practical opportunity to explore AI techniques, integrating NN and GA to demonstrate their application in gaming.

## Why this project was made
- As aspiring software developers, we are driven by the desire to expand our knowledge and skillset beyond the traditional boundaries of programming.
- The development of this project is fueled by the need to gain hands-on experience in integrating AI and machine learning techniques into a game-based environment.
- Game scenarios, with their controlled yet challenging nature, provide an ideal testbed for evaluating and validating AI algorithms, as they mimic real-world decision-making processes in a simulated setting.

## Game Mechanics
- In the game the player controls a bird that constantly falls due to gravity. To prevent the bird from crashing into the ground, the player must use the **Spacebar** or **Up Arrow Key** to make it flap and stay aloft. The goal is to navigate through gaps between pipes to achieve the highest score.

  ![image](https://github.com/user-attachments/assets/451b5a71-9fdc-4e85-b6ff-f14981c6fa13)

## Neural Network
- FlapMind utilizes Feed Forward Neural Network (FFNN), which is the simplest forms of neural network.
- FFNNs operate with a straightforward architecture where data flows in a single direction—from input to output. This unidirectional flow of information simplifies the design and understanding of the network.

  ![image](https://github.com/user-attachments/assets/0ac7020e-6797-435f-a5b1-ec7780d4eab0)

## Genetic Algorithm
- Genetic Algorithms (GA) are optimization techniques inspired by the principles of natural selection and evolution. They work by simulating the process of natural evolution to solve complex problems.
- To enhance the performance of the Feed Forward Neural Network (FFNN) used in FlapMind, a Genetic Algorithm (GA) is employed.
- The GA helps in optimizing the neural network by evolving a population of solutions over time.

### Crossover
- Crossover is performed by combining the genetic material (weights and biases) of the two best-performing individuals. This process involves exchanging portions of the parents' genetic code to create new offspring.
- For FlapMind, a crossover rate of 49% is applied, meaning that there is a chance of 49% that the offspring will inherit traits from both parents. To introduce random variation and genetic diversity, each offspring has a 2% chance of undergoing mutation, where random adjustments are made to a portion of its weights.

  ![image](https://github.com/user-attachments/assets/79e5d172-58bf-4982-9fd3-6c47c19ea920)
