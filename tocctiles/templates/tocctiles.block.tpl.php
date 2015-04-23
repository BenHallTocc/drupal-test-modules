<?php 

if (strlen($title) > 0) 
{
    echo sprintf('<h2>%s</h2>', $title);
}
echo implode('', $tiles);