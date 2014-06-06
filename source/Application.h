#pragma once

class Application
{
	public:
	static Application& getInstance();

	~Application();
	void onRender();
	void onKeyPressed(unsigned char key, int x, int y);
	void onSpecialKeyPressed(int key, int x, int y);

  void initialize();

  bool getInitialized() const;

	private:
	bool m_isInitialized = false;
	float m_cameraPosX = 0.0f;

	static Application& instance;
	Application(); // Don't implement
	void operator=(Application const&); // Don't implement
};