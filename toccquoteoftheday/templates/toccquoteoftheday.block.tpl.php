<?php 

if (strlen($title) > 0) 
{
    echo sprintf('<h2>%s</h2>', $title);
}

echo sprintf('<div class="tocc-qotd">' .
                '<span class="tocc-qotd__quote">"%s"</span>' .
                '<span class="tocc-qotd__signature">%s</span>' .
                '<span><a href="%s" target="_blank" rel="nofollow" />Click Here</span></div>',
                $quote, $signature, $link);