#ifndef __TEXTURE_H__
	#define __TEXTURE_H__

class Texture {
	private:
		std::string Filename;

		int Width;
		int Height;

		SDL_Renderer* Renderer = NULL;
		SDL_Texture* SDLTexture = NULL;

	public:
		Texture();
		~Texture();

		bool Load(SDL_Renderer* Renderer, std::string Filename);

		void Render(int X, int Y);

		void Render(int X, int Y, int Width, int Height);

		void Render(int X, int Y, int Width, int Height, int SX, int SY, int SWidth, int SHeight);

		int GetWidth();
		int GetHeight();
};

#endif
