#pragma once
#include "model/canvas/RenderContext.h"
#include "model/canvas/Surface.h"
#include "view/canvas/SurfaceView.h"
#include "view/ILayout.h"

namespace Canvas {
	namespace Ui {
		class Layout : public ILayout {
		public:
			Canvas::Ui::Layout(Canvas::RenderContext& renderContext);

			/**
			* @brief Renders the CanvasSurface using the provided SDL_Renderer.
			*
			* @param renderer Pointer to an SDL_Renderer used for rendering.
			*/
			void render(SDL_Renderer* renderer) const override;

			/**
			* @brief Updates the widgets of the Layout using the provided SDL_Renderer.
			*
			* @param renderer SDL_Renderer used for rendering.
			*/
			void updateWidgets(SDL_Renderer* renderer) override;

			Canvas::View::SurfaceView& getSurfaceView();

		private:
			int32_t& layoutWidth;
			int32_t& layoutHeight;
			Canvas::RenderContext& renderContext;
			Canvas::View::SurfaceView surfaceView;
			Canvas::Ui::StatusBar statusBar;
		};
	}
}
