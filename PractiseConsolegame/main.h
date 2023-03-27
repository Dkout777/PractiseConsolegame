#pragma once

#include "main.g.h"

namespace winrt::PractiseConsolegame::implementation
{
    struct main : mainT<main>
    {
        main();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::PractiseConsolegame::factory_implementation
{
    struct main : mainT<main, implementation::main>
    {
    };
}
