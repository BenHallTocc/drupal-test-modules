<?php

echo sprintf('<area class="toccmap_area_link" shape="poly" coords="%s" ' .
                'href="%s" data-imgsrc="%s">', 
                $coordinates,
                $link,
                $hoverimage);