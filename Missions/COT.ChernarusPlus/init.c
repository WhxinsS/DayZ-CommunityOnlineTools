static void SetupWeather()
{
    Weather weather = g_Game.GetWeather();

    weather.GetOvercast().SetLimits( 0.0 , 2.0 );
    weather.GetRain().SetLimits( 0.0 , 2.0 );
    weather.GetFog().SetLimits( 0.0 , 2.0 );

    weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.0 );
    weather.GetRain().SetForecastChangeLimits( 0.0, 0.0 );
    weather.GetFog().SetForecastChangeLimits( 0.0, 0.0 );
    weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
    weather.GetRain().SetForecastTimeLimits( 600 , 600 );
    weather.GetFog().SetForecastTimeLimits( 600 , 600 );

    weather.GetOvercast().Set( 0.0, 0, 0 );
    weather.GetRain().Set( 0.0, 0, 0 );
    weather.GetFog().Set( 0.0, 0, 0 );
    weather.SetWindMaximumSpeed( 50 );
    weather.SetWindFunctionParams( 0, 0, 1 );
}

void main()
{
	SetupWeather();

    if ( GetGame().IsServer() && !GetGame().IsMultiplayer() )
    {
        // GetGame().SelectPlayer( NULL, CreateCustomDefaultCharacter() );
    }
}