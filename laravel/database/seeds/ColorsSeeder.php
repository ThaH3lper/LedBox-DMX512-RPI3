<?php

use Illuminate\Database\Seeder;

class ColorsSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        DB::table('colors')->insert([[
        	'id' => 0,
            'red' => 255,
            'green' => 0,
            'blue' => 0,
        ],
        [
        	'id' => 1,
            'red' => 0,
            'green' => 255,
            'blue' => 0,
        ],
        [
        	'id' => 2,
            'red' => 0,
            'green' => 0,
            'blue' => 255,
        ]]);
    }
}
