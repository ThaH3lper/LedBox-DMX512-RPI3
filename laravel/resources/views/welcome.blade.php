<!DOCTYPE html>
<html>
    <head>
        <title>Laravel</title>

        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
        <meta name="viewport" content="width=device-width, initial-scale=1">

    </head>
    <body>
        <div class="container">
            <div class="row">
              <div class="col-lg-12">
                  <!--<div class="jumbotron">-->
                    <h1 class="text-center">Ledlight</h1>
                    <img src="https://img00.deviantart.net/434b/i/2015/031/e/c/hd_desktop_background__galaxy_cat_by_pattersondesigns-d8g4mn9.png" width="100%">
                    <p class="lead"></p>
                    <p><a class="btn-block btn-lg btn-success" href="{{ action('SendController@singleColorView') }}" role="button">Set single channel</a></p>
                    <p><a class="btn-block btn-lg btn-success" href="{{ action('SendController@allsend') }}" role="button">Set all channels</a></p>
                    <p><a class="btn-block btn-lg btn-primary" href="{{ action('SendController@sliderpicker') }}" role="button">Set all channels, Beta</a></p>
                  <!--</div>-->
              </div>
            </div>
        </div>
    </body>
</html>
