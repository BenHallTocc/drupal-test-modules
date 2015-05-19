<?php

$area_info = '';

if ($name && strlen($name) > 0)
{
    $area_info .= sprintf('<span class="toccmap_area_info_title"><h3>%s</h3>', $name);
}

if ($description && strlen($description) > 0)
{
    $area_info .= sprintf('<span class="toccmap_area_info_desc">%s</span>', $description);
}

if ($linktitle && strlen($linktitle) > 0)
{
    $area_info .= sprintf('<a href="%s">' .
                                '<span class="toccmap_area_info_button c-button">%s' .
                                '</span></a>', $link, $linktitle);
}

echo sprintf('<div class="toccmap_area_info")>%s</div>', $area_info);