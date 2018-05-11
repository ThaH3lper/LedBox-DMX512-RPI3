<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Http\Controllers\Controller;
use Symfony\Component\Process\Process;
use Symfony\Component\Process\Exception\ProcessFailedException;

class SendController extends Controller
{
    public function welcome(Request $request)
    {
        return view('welcome');
    }

    public function allsend(Request $request)
    {
    	$color = $request->input('color');
    	$process = new Process('led ' . substr($color, 0, 2) . ' ' . substr($color, 2, 2) . ' ' . substr($color, 4, 2));
		$process->run();
        return view('allsend', ['name' => $color]);
    }

    public function sliderpicker(Request $request)
    {
        $color = $request->input('color');
        $process = new Process('led ' . substr($color, 0, 2) . ' ' . substr($color, 2, 2) . ' ' . substr($color, 4, 2));
        $process->run();
        return view('sliderpicker', ['color_hex' => $color]);
    }

    public function singleColorView(Request $request)
    {
        $channel = $request->input('channel');
        $color = $request->input('color');
        $process = new Process('led ' . $channel . ' ' . substr($color, 0, 2) . ' ' . substr($color, 2, 2) . ' ' . substr($color, 4, 2));
        $process->run();
        return view('singlesend', ['color' => $color]);
    }

    public function update(Request $request, $id)
    {
        
    }
}
