<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Http\Controllers\Controller;
use Symfony\Component\Process\Process;
use Symfony\Component\Process\Exception\ProcessFailedException;

class SendController extends Controller
{
    public function testview(Request $request)
    {
    	$red = $request->input('color');
    	$process = new Process('test.exe ' . hexdec(substr($red, 4, 2)) . ' ' . hexdec(substr($red, 2, 2)) . ' ' . hexdec(substr($red, 0, 2)));
		$process->run();
        return view('testsend', ['name' => $red]);
    }

    public function update(Request $request, $id)
    {
        
    }
}
