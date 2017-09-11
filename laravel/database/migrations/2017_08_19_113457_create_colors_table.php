<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateColorsTable extends Migration
{
    public function up()
    {
        Schema::create('colors', function (Blueprint $table) {
            $table->increments('id');
            $table->integer('red');
            $table->integer('green');
            $table->integer('blue');
            $table->timestamp('created_at');
        });
    }

    public function down()
    {
        Schema::drop('colors');
    }
}
