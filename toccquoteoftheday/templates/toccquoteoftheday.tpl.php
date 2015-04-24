<?php

echo sprintf('<div class="tocc-qotd"><a href="%s" target="_blank" rel="nofollow">' .
                '<span class="tocc-qotd__quote">"%s"</span>' .
                '<span class="tocc-qotd__signature">%s, %s - %s</span>' .
                '</a></div>',
                $link, $quote, $quotee, $location, $added_info);

