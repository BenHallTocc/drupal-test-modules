<?php

$area_panel = '';

if ($image && strlen($image) > 0)
{
    $area_panel .= sprintf('%s', $image);
}

if ($title && strlen($title) > 0)
{
    $area_panel .= sprintf('<span class="toccmap_area_panel_title"><h3>%s</h3>', $title);
}

if ($desc && strlen($desc) > 0)
{
    $area_panel .= sprintf('<span class="toccmap_area_panel_desc">%s</span>', $desc);
}

if ($buttontext && strlen($buttontext) > 0)
{
    $area_panel .= sprintf('<a href="%s">' .
                                '<span class="toccmap_area_panel_button c-button">%s' .
                                '</span></a>', $link, $buttontext);
}

echo sprintf('<div class="toccmap_area_panel")>%s</div>', $area_panel);

