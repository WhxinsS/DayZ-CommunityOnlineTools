class JMPlayerRowWidget extends ScriptedWidgetEventHandler 
{
	protected Widget layoutRoot;

	TextWidget Name;
	ButtonWidget Button;
	CheckBoxWidget Checkbox;

	JMPlayerInstance Player;

	JMPlayerForm Menu;

	void OnWidgetScriptInit( Widget w )
	{
		layoutRoot = w;
		layoutRoot.SetHandler( this );
		Init();
	}

	void Init() 
	{
		Name = TextWidget.Cast(layoutRoot.FindAnyWidget("text_name"));
		Button = ButtonWidget.Cast(layoutRoot.FindAnyWidget("button"));
		Checkbox = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("checkbox"));
	}

	void Show()
	{
		layoutRoot.Show( true );
		Button.Show( true );
		Checkbox.Show( true );
		Name.Show( true );
		OnShow();
	}

	void Hide()
	{
		OnHide();
		Name.Show( false );
		Button.Show( false );
		Checkbox.Show( false );
		layoutRoot.Show( false );
	}

	void OnShow()
	{
	}

	void OnHide() 
	{
	}

	void Update() 
	{
		
	}

	ref Widget GetLayoutRoot() 
	{
		return layoutRoot;
	}

	void SetPlayer( JMPlayerInstance player )
	{
		Player = player;
		
		if ( Player == NULL ) 
		{
			Hide();
		} else 
		{
			Show();

			if ( !GetGame().IsMultiplayer() )
			{
				Name.SetText( "Offline Mode" );
				Name.SetColor( 0xFF2ECC71 );
				return;
			}

			Name.SetText( Player.Data.SName );
			Name.SetColor( 0xFFFFFFFF );

			if ( ClientAuthPlayer == NULL )
				return;

			if ( ClientAuthPlayer.IdentityPlayer == NULL )
				return;

			if ( !GetGame().IsMultiplayer() )
				return;

			//Message( GetGame().GetPlayer(), "CSID: " + ClientAuthPlayer.IdentityPlayer.GetPlainId() );
			//Message( GetGame().GetPlayer(), "SSID: " + Player.Data.SSteam64ID );

			if ( Player.Data.SSteam64ID == ClientAuthPlayer.IdentityPlayer.GetPlainId() )
			{
				Name.SetColor( 0xFF2ECC71 );
			}
		}
	}

	string GetName()
	{
		return Player.Data.SName;
	}

	JMPlayerInstance GetPlayer()
	{
		return Player;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{		
		if ( w == Checkbox )
		{
			Menu.OnPlayer_Checked( this );
		}

		if ( w == Button )
		{
			Menu.OnPlayer_Button( this );
		}

		return true;
	}
}