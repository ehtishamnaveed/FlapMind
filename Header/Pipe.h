#ifndef PIPE_H
#define PIPE_H

namespace Game {
	class Pipe {
	public:
		Pipe(short x, unsigned short y);
		void draw(sf::RenderWindow& i_window);
		void update();
		const bool isRemoveable() const;
		const short getXPosition() const ;
		const unsigned short getYPosition() const;
		static const unsigned short getGapSize() ;

	private:
		// bool direction;
		short X_Position;
		unsigned short Y_Position;
		static constexpr short OffScreenLimit = -50;
		// unsigned char y_MovementTimer;
		static constexpr unsigned char GapSize = 100;

		sf::Sprite pipe;
		sf::Texture texture;
	};
}

#endif