<?php

use Illuminate\Database\Seeder;

class PresetsSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        DB::table('presets')->insert([
        	'name' => "Test preset",
            'description' => "This is a beautiful preset of colors",
            'color_one' => 0,
            'color_two' => 1,
            'color_three' => 2,
            'color_four' => 2,
            'color_five' => 1,
            'color_six' => 0,
        ]);
    }
}
