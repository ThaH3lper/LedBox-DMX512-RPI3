<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Http\Controllers\Controller;
use Symfony\Component\Process\Process;
use Symfony\Component\Process\Exception\ProcessFailedException;

class SendController extends Controller
{
    private function hexToInt($hex)
    {
        return max(0, min(127, floor(hexdec($hex) / 2)));
    }

    public function welcome(Request $request)
    {
        return view('welcome');
    }

    public function allsend(Request $request)
    {
    	$color = $request->input('color');
        $red = max(0, min(127, floor(hexdec(substr($color, 0, 2)) / 2)));
        $green = max(0, min(127, floor(hexdec(substr($color, 2, 2)) / 2)));
        $blue = max(0, min(127, floor(hexdec(substr($color, 4, 2)) / 2)));
    	$process = new Process('Led all 1 ' . $red . ' ' . $green . ' ' . $blue);
		$process->run();
        return view('allsend', ['name' => 'Led all 1 ' . $red . ' ' . $green . ' ' . $blue]);
    }

    public function sliderpicker(Request $request)
    {
        $color = $request->input('color');
        $red = max(0, min(127, floor(hexdec(substr($color, 0, 2)) / 2)));
        $green = max(0, min(127, floor(hexdec(substr($color, 2, 2)) / 2)));
        $blue = max(0, min(127, floor(hexdec(substr($color, 4, 2)) / 2)));
        $process = new Process('Led all 1  ' . $red . ' ' . $green . ' ' . $blue);
        $process->run();
        return view('sliderpicker', ['color_hex' => $color]);
    }

    public function singleColorView(Request $request)
    {
        $channel = $request->input('channel');
        $color = $request->input('color');
        $red = max(0, min(127, floor(hexdec(substr($color, 0, 2)) / 2)));
        $green = max(0, min(127, floor(hexdec(substr($color, 2, 2)) / 2)));
        $blue = max(0, min(127, floor(hexdec(substr($color, 4, 2)) / 2)));
        $process = new Process('Led channel ' . $channel . ' 1 ' . $red . ' ' . $green . ' ' . $blue);
        $process->run();
        return view('singlesend', ['color' => $color]);
    }

    public function update(Request $request, $id)
    {
        
    }
}
