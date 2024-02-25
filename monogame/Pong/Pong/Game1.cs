using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace Pong;

public class Game1 : Game
{
    private Texture2D _ballTexture;
    private Vector2 _ballPosition;
    private float _ballSpeed;

    Texture2D _playerTexture;
    private Rectangle _playerRectangle;
    private Point _playerPosition;

    private Rectangle _opponentRectangle;
    private Point _opponentPosition;

    private GraphicsDeviceManager _graphics;
    private SpriteBatch _spriteBatch;

    public Game1()
    {
        _graphics = new GraphicsDeviceManager(this);
        Content.RootDirectory = "Content";
        IsMouseVisible = true;
    }

    protected override void Initialize()
    {
        // TODO: Add your initialization logic here
        _ballPosition = new Vector2(_graphics.PreferredBackBufferWidth / 2, _graphics.PreferredBackBufferHeight / 2);
        _ballSpeed = 100f;

        _playerRectangle = new Rectangle(_playerPosition, new Point(_graphics.PreferredBackBufferWidth / 4, _graphics.PreferredBackBufferHeight / 16));
        _playerTexture = new Texture2D(_graphics.GraphicsDevice, 1, 1);
        _playerTexture.SetData(new[] { Color.Red });

        base.Initialize();
    }

    protected override void LoadContent()
    {
        _spriteBatch = new SpriteBatch(GraphicsDevice);

        // TODO: use this.Content to load your game content here
        _ballTexture = Content.Load<Texture2D>("ball");
    }

    protected override void Update(GameTime gameTime)
    {
        if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed ||
            Keyboard.GetState().IsKeyDown(Keys.Escape))
            Exit();

        // TODO: Add your update logic here
        var keyState = Keyboard.GetState();
        if (keyState.IsKeyDown(Keys.A))
        {
            _playerRectangle.X -= 10;
        }
        else if (keyState.IsKeyDown(Keys.E))
        {
            _playerRectangle.X += 10;
        }

        base.Update(gameTime);
    }

    protected override void Draw(GameTime gameTime)
    {
        GraphicsDevice.Clear(Color.CornflowerBlue);

        // TODO: Add your drawing code here
        _spriteBatch.Begin();
        _spriteBatch.Draw(
            _ballTexture,
            _ballPosition,
            null,
            Color.White,
            0f,
            new Vector2(_ballTexture.Width / 2, _ballTexture.Height / 2),
            Vector2.One,
            SpriteEffects.None,
            0f
        );
        _spriteBatch.Draw(_playerTexture, _playerRectangle, Color.Red);
        _spriteBatch.End();

        base.Draw(gameTime);
    }
}