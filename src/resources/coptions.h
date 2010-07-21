/**
 *  @section LICENSE
 *
 *  openPirates
 *  Copyright (C) 2010 Scott Smith
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COPTIONS_H
#define COPTIONS_H

#include "global.h"
#include "resources/cini.h"
#include "resources/ccontrols.h"

#define SCREEN_MODES    10
#define SCREEN_DEPTHS   3
extern uint16_t limitsScreenWidth[SCREEN_MODES];
extern uint16_t limitsScreenHeight[SCREEN_MODES];
extern uint16_t limitsScreenDepth[SCREEN_DEPTHS];

#define SOUND_FREQ      4
#define SOUND_CHANNELS  2
#define SOUND_SAMPLE    6
extern uint16_t limitsSoundFreq[SOUND_FREQ];
extern uint16_t limitsSoundChannels[SOUND_CHANNELS];
extern uint16_t limitsSoundSamples[SOUND_SAMPLE];

#define VERIFY_RANGE(val,cur,max) (val<max) ? val : cur

/**
 * @section DESCRIPTION
 * This class handles the screen options for the application.
 */

class CScreenOptions
{
    public:
        /** Constructor. */
        CScreenOptions() :
            mVideoMode  (DEF_SCREEN_VMODE),
            mDepthMode  (DEF_SCREEN_BPP),
            mFullscreen (DEF_FULLSCREEN),
            mDoublebuf  (DEF_DOUBLEBUF)
        {
        }
        /** Destructor. */
        virtual ~CScreenOptions() {}

        // Getters
        uint8_t     VideoMode( void )   { return mVideoMode; }
        uint8_t     DepthMode( void )   { return mDepthMode; }
        uint16_t    Width( void )       { return limitsScreenWidth[mVideoMode]; }
        uint16_t    Height( void )      { return limitsScreenHeight[mVideoMode]; }
        uint8_t     Depth( void )       { return limitsScreenDepth[mDepthMode]; }
        bool        Fullscreen( void )  { return mFullscreen; }
        bool        Doublebuf( void )   { return mDoublebuf; }
        // Setters
        void VideoMode( uint8_t v )     { mVideoMode = VERIFY_RANGE( v, mVideoMode, SCREEN_MODES ); }
        void DepthMode( uint8_t v )     { mDepthMode = VERIFY_RANGE( v, mDepthMode, SCREEN_DEPTHS ); }
        void Fullscreen( bool v )       { mFullscreen = v; }
        void Doublebuf( bool v )        { mDoublebuf = v; }
        void CustomMode( uint16_t w, uint16_t h )
        {
            mVideoMode = 0;
            limitsScreenWidth[0]  = w;
            limitsScreenHeight[0] = h;
        }

    private:
        uint8_t     mVideoMode;
        uint8_t     mDepthMode;
        bool        mFullscreen;
        bool        mDoublebuf;
};

/**
 * @section DESCRIPTION
 * This class handles the mixer (sound) options for the application.
 */

class CSoundOptions
{
    public:
        /** Constructor. */
        CSoundOptions() :
            mChannelsMode   (DEF_SOUND_CHAN),
            mFrequencyMode  (DEF_SOUND_FREQ),
            mSampleSizeMode (DEF_SOUND_SAMPLE)
        {
        }
        /** Destructor. */
        virtual ~CSoundOptions() {}

        // Getters
        uint8_t ChannelsMode( void )    { return mChannelsMode; }
        uint8_t FrequencyMode( void )   { return mFrequencyMode; }
        uint8_t SampleSizeMode( void )  { return mSampleSizeMode; }
        uint8_t Channels( void )        { return limitsSoundChannels[mChannelsMode]; }
        uint16_t Frequency( void )      { return limitsSoundFreq[mFrequencyMode]; }
        uint16_t SampleSize( void )     { return limitsSoundSamples[mSampleSizeMode]; }
        // Setters
        void ChannelsMode( uint8_t v )      { mChannelsMode   = VERIFY_RANGE(v, mChannelsMode,   SOUND_CHANNELS ); }
        void FrequencyMode( uint16_t v )    { mFrequencyMode  = VERIFY_RANGE(v, mFrequencyMode,  SOUND_FREQ ); }
        void SampleSizeMode( uint16_t v )   { mSampleSizeMode = VERIFY_RANGE(v, mSampleSizeMode, SOUND_SAMPLE ); }

    private:
        uint8_t     mChannelsMode;
        uint16_t    mFrequencyMode;
        uint16_t    mSampleSizeMode;
};

/**
 * @section DESCRIPTION
 * This class handles the font options for the application.
 */

class CFontOptions
{
    public:
        /** Constructor. */
        CFontOptions() :
            mSize   (DEF_FONT_SIZE),
            mColor  (),
            mPath   (DEF_FONT_PATH)
        {
            // White
            mColor.r = DEF_FONTCOLOR_R;
            mColor.g = DEF_FONTCOLOR_G;
            mColor.b = DEF_FONTCOLOR_B;
        }
        /** Destructor. */
        virtual ~CFontOptions() {}

        // Getters
        uint8_t             Size( void )    { return mSize; }
        SDL_Color*          Color( void )   { return &mColor; }
        const std::string&  Path( void )    { return mPath; }
        // Setters
        void Size( uint8_t v )              { mSize = v; }
        void Color( SDL_Color v )           { mColor = v; }
        void Path( const std::string& v )   { mPath = v; }

    private:
        uint8_t     mSize;
        SDL_Color   mColor;
        std::string mPath;
};

/**
 * @section DESCRIPTION
 * This class handles the wave options for the application.
 */

class CWaveOptions
{
    public:
        /** Constructor. */
        CWaveOptions() :
            mCount  (DEF_WAVE_COUNT),
            mSpeed  (DEF_WAVE_SPEED)
        {
        }
        /** Destructor. */
        virtual ~CWaveOptions() {}

        // Getters
        uint8_t Count( void )       { return mCount; }
        uint8_t Speed( void )       { return mSpeed; }
        // Setters
        void Count( uint8_t count ) { mCount = count; }
        void Speed( uint8_t speed ) { mSpeed = speed; }

    private:
        uint8_t mCount;
        uint8_t mSpeed;
};

/**
 * @section DESCRIPTION
 * This class handles the cloud options for the application.
 */

class CCloudOptions
{
    public:
        /** Constructor. */
        CCloudOptions() :
            mCount(DEF_CLOUD_COUNT)
        {
        }
        /** Destructor. */
        virtual ~CCloudOptions() {}

        // Getters
        uint8_t Count( void )       { return mCount; }
        // Setters
        void Count( uint8_t count ) { mCount = count; }

    private:
        uint8_t mCount;
};

/**
 * @section DESCRIPTION
 * This class handles the map options for the application.
 */

class CMapOptions
{
    public:
        /** Constructor. */
        CMapOptions() :
            mWidth  (0),
            mHeight (0)
        {
        }
        /** Destructor. */
        virtual ~CMapOptions() {}

        // Getters
        uint16_t Width( void )          { return mWidth; }
        uint16_t Height( void )         { return mHeight; }
        // Setters
        void Width( uint16_t width )    { mWidth = width; }
        void Height( uint16_t height )  { mHeight = height; }

    private:
        uint16_t    mWidth;
        uint16_t    mHeight;
};

/**
 * @section DESCRIPTION
 * This class handles the configuration options for the application, such as (but not limited to) screen and mixer settings.
 */

class COptions : public CIni
{
    public:
        /** Constructor. */
        COptions();
        /** Destructor. */
        virtual ~COptions();

        // Getters
        CScreenOptions&     Screen( void )      { return mScreen; }
        CSoundOptions&      Sound( void )       { return mSound; }
        CFontOptions&       Font( void )        { return mFont; }
        CControls&          Controls( void )    { return mControls; }
        CWaveOptions&       Wave( void )        { return mWave; }
        CCloudOptions&      Cloud( void )       { return mCloud; }
        CMapOptions&        Map( void )         { return mMap; }

        int8_t Load( const std::string& base_path );
        int8_t Save( const std::string& base_path );

    private:
        CScreenOptions  mScreen;
        CSoundOptions   mSound;
        CFontOptions    mFont;
        CControls       mControls;
        CWaveOptions    mWave;
        CCloudOptions   mCloud;
        CMapOptions     mMap;
};

#endif // COPTIONS_H
