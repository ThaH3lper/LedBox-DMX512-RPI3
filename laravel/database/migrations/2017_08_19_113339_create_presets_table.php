<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreatePresetsTable extends Migration
{
    public function up()
    {
        Schema::create('presets', function (Blueprint $table) {
            $table->increments('id');
            $table->string('name');
            $table->string('description');

            $table->integer('color_one');
            $table->integer('color_two');
            $table->integer('color_three');
            $table->integer('color_four');
            $table->integer('color_five');
            $table->integer('color_six');

            $table->timestamp('created_at');
        });
    }

    public function down()
    {
        Schema::drop('presets');
    }
}
