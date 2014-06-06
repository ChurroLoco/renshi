#pragma once

class Application
{
	public:
	static Application& getInstance();

	~Application();
	void onRender();
	void onKeyPressed(unsigned char key, int x, int y);
	void onSpecialKeyPressed(int key, int x, int y);
	void onUpdate();

  void initialize();

  bool getInitialized() const;

	private:
	bool m_isInitialized = false;  // True if initialize() has been successfully ran
	float m_cameraPosX = 0.0f;	   // The position of the camera on the X axis
	double m_lastUpdate = 0.0;     // The last time onUpdate was called
	
	static Application& instance;
	Application(); // Don't implement
	void operator=(Application const&); // Don't implement
};