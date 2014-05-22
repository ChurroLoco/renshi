#pragma once

class RenshiApp
{
	public:
	static RenshiApp& getInstance();
	
	~RenshiApp();
	void onRender();
	void onKeyPressed(unsigned char key, int x, int y);
	
	private:
	static RenshiApp& instance;
	RenshiApp(); // Don't implement
	void operator=(RenshiApp const&); // Don't implement
};