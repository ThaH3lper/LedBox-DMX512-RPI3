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
                  <div class="jumbotron">
                    <h1 class="display-3">Ledlight</h1>
                    <p class="lead">Start ledlight control</p>
                    <p><a class="btn btn-lg btn-success" href="{{ action('SendController@testview') }}" role="button">Start now</a></p>
                  </div>
              </div>
            </div>
        </div>
    </body>
</html>