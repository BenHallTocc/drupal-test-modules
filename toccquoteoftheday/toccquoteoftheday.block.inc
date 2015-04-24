<?php

/**
 * Implements hook_block_info()
 * 
 * @return array
 */
function toccquoteoftheday_block_info()
{
    $blocks['toccquoteoftheday_block'] = array(
        'info' => t('TOCC Quote of the Day'),
    );
    
    return $blocks;
}

/**
 * Implements hook_block_view()
 * 
 * Prepares the contents of the block.
 * 
 * @return array
 */
function toccquoteoftheday_block_view($delta = '')
{
    $block = array();
    $title = '';
    
    switch($delta) {
        case 'toccquoteoftheday_block':
            $title = db_query(
                    "SELECT title FROM {block} where delta='" . $delta . "' and `status`=1"
            )->fetchField();
            break;
    }
        
    switch($delta) {
        case 'toccquoteoftheday_block':
            $qotd = _toccquoteoftheday_get_quote();
               
            $quote = $qotd->qotd_quote->value();
            $signature = $qotd->qotd_quotee->value();
            $location = $qotd->qotd_location->value();
            $additional_info = $qotd->qotd_added_info->value();
            
            if(!$location == '') {
                $signature = $signature . ', ' . $location . ' ';
            }
            
            if(!$additional_info == '') {
                $signature = $signature . '- ' . $additional_info;
            }
            
            $link = $qotd->qotd_link->value();
                           
            $block['subject'] = t('TOCC Quote of the Day');
            $block['content']['#markup'] = theme(
                $delta,
                array(
                    'title' => $title,
                    'quote' => $quote,
                    'signature' => $signature,
                    'link' => $link
                )
            );
            
            break;
    }
    
    return $block;
}

//--------------- Helper Methods ---------------//

/**
 * Return a quote from the taxonomy at random
 * 
 * @return array
 */
function _toccquoteoftheday_get_quote()
{
    $quotes = tabs_api_get_vocabulary('toccquoteoftheday');
    $active_quotes = array_filter($quotes, function($ele) {
        return $ele->qotd_active->value() == 1;
    });
    
    return array_rand($active_quotes, 1);
}

