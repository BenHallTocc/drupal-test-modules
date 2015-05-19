<?php 

// TOCC Map Menu
$list = '';

foreach ($area_menu as $menu_item)
{
    $list .= sprintf('<li>%s</li>', $menu_item);
}

echo sprintf('<div class="toccmap_menu">' .
                '<ul class="links">%s</ul>' .
             '</div>', $list);

// TOCC Map Area Info
echo implode('', $areas_info);

// TOCC Map
$areas = implode('', $map_areas);

echo sprintf('<div class="toccmap_map">' .
                '<map name="toccmap" id="toccmap">%s</map></div>', $areas);
