module;

/**
 * Module for simple GUI (graphical user interface)
 * Wrapper for your favourite (not QT) library
 * Version - 0.0.2
 */

/*
 * Your includes here
 */
#include "FL/Fl_Widget.H"
#include "FL/Fl_Window.H"

export module Guilib;

// #define DEBUG_GUI //uncomment this

/**
 * Global namespace for library
 */
export namespace Guilib {
    /**
     * Namespace for useful actions
     */
    namespace Utility {
        /**
         * Get current window child by its position.
         * widget - element of the main window
         * @tparam position position of the widget on window from 0 to n.
         * @return child by given position
         */
        template<int position>
        auto SELF_GET_CHILD = [](Fl_Widget *widget) {
#ifdef DEBUG_GUI
            printf("Get position - %d", position);
#endif
            return widget->top_window()->as_window()->child(position);
        };

        /**
         * Get current entity window.
         * widget - element of the main window
         * @return self
         */
        auto SELF = [](Fl_Widget *widget) -> auto {
            return widget->top_window()->as_window();
        };
    }

    /**
     * Namespace for gui elements
     */
    namespace Elements {
        /**
         * Simple button wrapper.
         */
        class FLTK_button {
            bool state = false; //button state

        public:
            FLTK_button();

            FLTK_button(const FLTK_button &) = delete;

            ~FLTK_button();

            //methods:
            [[nodiscard]] auto get_state() const -> bool {
                return state;
            }
        };
    }
}
