<?php

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an application.
| It's a breeze. Simply tell Laravel the URIs it should respond to
| and give it the controller to call when that URI is requested.
|
*/

Route::get('/', 'SendController@welcome');

Route::get('/sliderpicker', 'SendController@sliderpicker');

Route::get('/allsend', 'SendController@allsend');

Route::get('/channel', 'SendController@singleColorView');

Route::get('/api', 'SendController@api');
