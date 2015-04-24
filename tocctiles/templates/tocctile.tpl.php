<?php

echo sprintf('<div class="tocc-tile">' .
                    '<h3><a href="%s" target="_self">%s%s</h3></a>' .
                        '<span class="tocc-tile__desc">%s</span>' .
                        '<span class="tocc-tile__button">%s</span></div>',
                        $link, $image, $name, $description, $buttontext);

