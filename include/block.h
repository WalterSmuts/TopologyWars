#ifndef BLOCK_H
#define BLOCK_H

class Block
{
	public:
	Block();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	void update(int ticks);

	private:
	int x;
	int y;
	int width;
	int height;
};

#endif // BLOCK_H
