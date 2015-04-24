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
            $quotes = _toccquoteoftheday_get_quotes();
            $quotes_themed = array();
            
            foreach ($quotes as $taxid => $field) {
                $quote = $field->qotd_quote->value();
                $quotee = $field->qotd_quotee->value();
                $location = $field->qotd_location->value();
                $added_info = $field->qotd_added_info->value();
                $link = $field->qotd_link->value();
                
                $quotes_themed[] = theme(
                    'toccquote',
                    array(
                        'quote' => $quote,
                        'quotee' => $quotee,
                        'location' => $location,
                        'added_info' => $added_info,
                        'link' => $link
                    )
                );
            }
            
            $block['subject'] = t('TOCC Quote of the Day');
            $block['content']['#markup'] = theme(
                $delta,
                array(
                    'title' => $title,
                    'quotes' => $quotes_themed
                )
            );
            
            break;
    }
    
    return $block;
}

//--------------- Helper Methods ---------------//

/**
 * Return the Quotes taxonomy
 * 
 * @return array
 */
function _toccquoteoftheday_get_quotes()
{
    $quotes = tabs_api_get_vocabulary('toccquoteoftheday');
    
    return array_filter($quotes, function($ele) {
        return $ele->qotd_active->value() == 1;
    });
}

