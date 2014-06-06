#pragma once

class RenshiApp
{
	public:
	static RenshiApp& getInstance();

	~RenshiApp();
	void onRender();
	void onKeyPressed(unsigned char key, int x, int y);
	void onSpecialKeyPressed(int key, int x, int y);

  void initialize();

  bool getInitialized() const;

	private:
	bool m_isInitialized = false;
	float m_cameraPosX = 0.0f;

	static RenshiApp& instance;
	RenshiApp(); // Don't implement
	void operator=(RenshiApp const&); // Don't implement
};