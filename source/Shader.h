class Shader
{
	char* source;
	char* compilationErrors;
	uint glShaderIndex;

	public:
	int loadSource(const char* source);
	void freeSource();
	void free+Errors()
	const char* getSource();
	void* compileSource();
}
