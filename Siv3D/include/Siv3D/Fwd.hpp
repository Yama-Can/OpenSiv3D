//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2018 Ryo Suzuki
//	Copyright (c) 2016-2018 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include "Platform.hpp"
# include "Types.hpp"

namespace s3d
{
	//////////////////////////////////////////////////////
	//
	//	PlaceHolder.hpp
	//
	struct PlaceHolder_t;

	//////////////////////////////////////////////////////
	//
	//	Uncopyable.hpp
	//
	class Uncopyable;

	//////////////////////////////////////////////////////
	//
	//	Byte.hpp
	//
	enum class Byte : unsigned char;

	//////////////////////////////////////////////////////
	//
	//	ByteArrayView.hpp
	//
	class ByteArrayView;

	//////////////////////////////////////////////////////
	//
	//	ConcurrentTask.hpp
	//
	template <class Type> class ConcurrentTask;

	//////////////////////////////////////////////////////
	//
	//	AlignedAllocator.hpp
	//
	template <class Type, size_t Alignment> class AlignedAllocator;
	template <class Type> struct DefaultAllocator;

	//////////////////////////////////////////////////////
	//
	//	Array.hpp
	//
	template <class Type, class Allocator> class Array;

	//////////////////////////////////////////////////////
	//
	//	KDTree.hpp
	//
	template <class DatasetAdapter> class KDAdapter;
	template <class DatasetAdapter> class KDTree;

	//////////////////////////////////////////////////////
	//
	//	InfiniteList.hpp
	//
	template <class Type> class infinite_list;

	//////////////////////////////////////////////////////
	//
	//	Grid.hpp
	//
	template <class Type, class Allocator> class Grid;

	//////////////////////////////////////////////////////
	//
	//	Optional.hpp
	//
	struct None_t;
	template <class Type> class Optional;

	//////////////////////////////////////////////////////
	//
	//	RangeIterator.hpp
	//
	template <class Iterator> class RangeIterator;

	//////////////////////////////////////////////////////
	//
	//	StringView.hpp
	//
	class StringView;

	//////////////////////////////////////////////////////
	//
	//	String.hpp
	//
	class String;
	using FilePath = String;
	
	//////////////////////////////////////////////////////
	//
	//	Unicode.hpp
	//
	struct Translator_UTF8toUTF32;
	struct Translator_UTF16toUTF32;
	struct Translator_UTF32toUTF8;
	struct Translator_UTF32toUTF16;

	//////////////////////////////////////////////////////
	//
	//	LetterCase.hpp
	//
	enum class LetterCase;

	//////////////////////////////////////////////////////
	//
	//	BigInt.hpp
	//
	class BigInt;

	//////////////////////////////////////////////////////
	//
	//	BigFloat.hpp
	//
	class BigFloat;

	//////////////////////////////////////////////////////
	//
	//	Format.hpp
	//
	struct FormatData;

	//////////////////////////////////////////////////////
	//
	//	Date.hpp
	//
	struct Date;

	//////////////////////////////////////////////////////
	//
	//	DateTime.hpp
	//
	struct DateTime;

	//////////////////////////////////////////////////////
	//
	//	Stopwatch.hpp
	//
	class Stopwatch;

	//////////////////////////////////////////////////////
	//
	//	CustomStopwatch.hpp
	//
	class CustomStopwatch;

	//////////////////////////////////////////////////////
	//
	//	Timer.hpp
	//
	class Timer;

	//////////////////////////////////////////////////////
	//
	//	TimeProfiler.hpp
	//
	class TimeProfiler;

	//////////////////////////////////////////////////////
	//
	//	MillisecClock.hpp
	//
	class MillisecClock;

	//////////////////////////////////////////////////////
	//
	//	MicrosecClock.hpp
	//
	class MicrosecClock;

	//////////////////////////////////////////////////////
	//
	//	RDTSCClock.hpp
	//
	class RDTSCClock;

	//////////////////////////////////////////////////////
	//
	//	FileSystem.hpp
	//
	enum class OpenMode;
	enum class CopyOption;
	enum class SpecialFolder;

	//////////////////////////////////////////////////////
	//
	//	IReader.hpp
	//
	class IReader;

	//////////////////////////////////////////////////////
	//
	//	IWriter.hpp
	//
	class IWriter;

	//////////////////////////////////////////////////////
	//
	//	ReaderView.hpp
	//
	class ReaderView;

	//////////////////////////////////////////////////////
	//
	//	MemoryMapping.hpp
	//
	class MemoryMapping;

	//////////////////////////////////////////////////////
	//
	//	WritableMemoryMapping.hpp
	//
	class WritableMemoryMapping;
	enum class MMFOpenMode_if_Exists;
	enum class MMFOpenMode_if_NotFound;

	//////////////////////////////////////////////////////
	//
	//	ByteArray.hpp
	//
	class ByteArray;

	//////////////////////////////////////////////////////
	//
	//	MemoryWriter.hpp
	//
	class MemoryWriter;

	//////////////////////////////////////////////////////
	//
	//	BinaryReader.hpp
	//
	class BinaryReader;

	//////////////////////////////////////////////////////
	//
	//	BinaryWriter.hpp
	//
	class BinaryWriter;

	//////////////////////////////////////////////////////
	//
	//	TextEncoding.hpp
	//
	enum class TextEncoding;

	//////////////////////////////////////////////////////
	//
	//	TextReader.hpp
	//
	class TextReader;

	//////////////////////////////////////////////////////
	//
	//	TextWriter.hpp
	//
	class TextWriter;

	//////////////////////////////////////////////////////
	//
	//	MD5.hpp
	//
	struct MD5Value;

	//////////////////////////////////////////////////////
	//
	//	LicenseManager.hpp
	//
	struct LicenseInfo;

	//////////////////////////////////////////////////////
	//
	//	Logger.hpp
	//
	enum class OutputLevel;
	enum class LogDescription;

	//////////////////////////////////////////////////////
	//
	//	CSVData.hpp
	//
	class CSVData;

	//////////////////////////////////////////////////////
	//
	//	INIData.hpp
	//
	class INIData;

	//////////////////////////////////////////////////////
	//
	//	JSONReader.hpp
	//
	enum class JSONValueType;
	class JSONArrayIterator;
	class JSONObjectIterator;
	class JSONArrayView;
	class JSONObjectView;
	class JSONValue;
	struct JSONObjectMember;
	class JSONReader;

	//////////////////////////////////////////////////////
	//
	//	TOMLReader.hpp
	//
	enum class TOMLValueType;
	class TOMLTableIterator;
	class TOMLTableView;
	class TOMLArrayIterator;
	class TOMLArrayView;
	class TOMLTableArrayIterator;
	class TOMLTableArrayView;
	class TOMLValue;
	struct TOMLTableMember;
	class TOMLReader;

	//////////////////////////////////////////////////////
	//
	//	HTMLWriter.hpp
	//
	class HTMLWriter;

	//////////////////////////////////////////////////////
	//
	//	Color.hpp
	//
	struct Color;
	struct ColorF;

	//////////////////////////////////////////////////////
	//
	//	HSV.hpp
	//
	struct HSV;

	//////////////////////////////////////////////////////
	//
	//	PointVector.hpp
	//
	struct Point;
	using Size = Point;
	template <class Type> struct Vector2D;
	template <class Type> struct Vector3D;
	template <class Type> struct Vector4D;
	using Float2	= Vector2D<float>;
	using Vec2		= Vector2D<double>;
	using Float3	= Vector3D<float>;
	using Vec3		= Vector3D<double>;
	using Float4	= Vector4D<float>;
	using Vec4		= Vector4D<double>;

	//////////////////////////////////////////////////////
	//
	//	Circular.hpp
	//
	template <int32 Oclock> struct CircularBase;
	using Circular  = CircularBase<0>;
	using Circular0 = CircularBase<0>;
	using Circular3 = CircularBase<3>;
	using Circular6 = CircularBase<6>;
	using Circular9 = CircularBase<9>;
		
	//////////////////////////////////////////////////////
	//
	//	OffsetCircular.hpp
	//
	template <int32 Oclock> struct OffsetCircularBase;
	using OffsetCircular  = OffsetCircularBase<0>;
	using OffsetCircular0 = OffsetCircularBase<0>;
	using OffsetCircular3 = OffsetCircularBase<3>;
	using OffsetCircular6 = OffsetCircularBase<6>;
	using OffsetCircular9 = OffsetCircularBase<9>;

	//////////////////////////////////////////////////////
	//
	//	Cylindrical.hpp
	//
	struct Cylindrical;

	//////////////////////////////////////////////////////
	//
	//	Spherical.hpp
	//
	struct Spherical;

	//////////////////////////////////////////////////////
	//
	//	Mat3x2.hpp
	//
	struct Mat3x2;

	//////////////////////////////////////////////////////
	//
	//	Line.hpp
	//
	struct LineStyle;
	struct Line;

	//////////////////////////////////////////////////////
	//
	//	Rectangle.hpp
	//
	template <class SizeType> struct Rectangle;
	using Rect = Rectangle<Point>;
	using RectF = Rectangle<Vec2>;

	//////////////////////////////////////////////////////
	//
	//	Circle.hpp
	//
	struct Circle;

	//////////////////////////////////////////////////////
	//
	//	Ellipse.hpp
	//
	struct Ellipse;

	//////////////////////////////////////////////////////
	//
	//	Triangle.hpp
	//
	struct Triangle;

	//////////////////////////////////////////////////////
	//
	//	Quad.hpp
	//
	struct Quad;

	//////////////////////////////////////////////////////
	//
	//	RoundRect.hpp
	//
	struct RoundRect;

	//////////////////////////////////////////////////////
	//
	//	LineString.hpp
	//
	class LineString;

	//////////////////////////////////////////////////////
	//
	//	Polygon.hpp
	//
	class Polygon;

	//////////////////////////////////////////////////////
	//
	//	Bezier2.hpp
	//
	struct Bezier2;
	struct Bezier2Path;

	//////////////////////////////////////////////////////
	//
	//	Bezier3.hpp
	//
	struct Bezier3;
	struct Bezier3Path;

	//////////////////////////////////////////////////////
	//
	//	FloatRect.hpp
	//
	struct FloatRect;

	//////////////////////////////////////////////////////
	//
	//	FloatQuad.hpp
	//
	struct FloatQuad;

	//////////////////////////////////////////////////////
	//
	//	Shape2D.hpp
	//
	class Shape2D;

	//////////////////////////////////////////////////////
	//
	//	Distribution.hpp
	//
	template <class Type> class UniformDistribution;
	template <class Type> class NormalDistribution;

	//////////////////////////////////////////////////////
	//
	//	HardwareRNG.hpp
	//
	class HardwareRNG;

	//////////////////////////////////////////////////////
	//
	//	Xorshift.hpp
	//
	class Xorshift64Star;
	class Xorshift128Plus;
	class Xorshift1024Star;

	//////////////////////////////////////////////////////
	//
	//	SFMT.hpp
	//
	class SFMT19937_64;

	//////////////////////////////////////////////////////
	//
	//	MersenneTwister.hpp
	//
	class MT11213b;
	class MT19937;
	class MT19937_64;

	//////////////////////////////////////////////////////
	//
	//	DefaultRNG.hpp
	//
	using DefaultRNGType = SFMT19937_64;

	//////////////////////////////////////////////////////
	//
	//	EasingController.hpp
	//
	template <class Type> class EasingController;

	//////////////////////////////////////////////////////
	//
	//	Transition.hpp
	//
	class Transition;

	//////////////////////////////////////////////////////
	//
	//	PerlinNoise.hpp
	//
	class PerlinNoise;

	//////////////////////////////////////////////////////
	//
	//	MathParser.hpp
	//
	class MathParser;

	//////////////////////////////////////////////////////
	//
	//	Image.hpp
	//
	enum class AdaptiveMethod;
	enum class BorderType;
	enum class FloodFillConnectivity;
	enum class Interpolation;
	class Image;

	//////////////////////////////////////////////////////
	//
	//	ImageFormat.hpp
	//
	enum class ImageFormat;
	enum class PPMType;
	class IImageFormat;

	//////////////////////////////////////////////////////
	//
	//	TextureFormat.hpp
	//
	enum class TextureFormat;

	//////////////////////////////////////////////////////
	//
	//	Exif.hpp
	//
	struct ExifInfo;

	//////////////////////////////////////////////////////
	//
	//	WaveSample.hpp
	//
	struct WaveSampleS16;
	struct WaveSample;

	//////////////////////////////////////////////////////
	//
	//	Wave.hpp
	//
	class Wave;

	//////////////////////////////////////////////////////
	//
	//	FFT.hpp
	//
	enum class FFTSampleLength;
	struct FFTResult;

	//////////////////////////////////////////////////////
	//
	//	AudioFormat.hpp
	//
	enum class AudioFormat;
	enum class WAVEFormat;
	class IAudioFormat;

	//////////////////////////////////////////////////////
	//
	//	CPU.hpp
	//
	enum class CPUVendor;
	struct CPUFeature;

	//////////////////////////////////////////////////////
	//
	//	Monitor.hpp
	//
	struct Monitor;

	//////////////////////////////////////////////////////
	//
	//	Window.hpp
	//
	enum class ShowState;
	struct WindowState;

	//////////////////////////////////////////////////////
	//
	//	MessageBox.hpp
	//
	enum class MessageBoxStyle;
	enum class MessageBoxButtons;
	enum class MessageBoxSelection;

	//////////////////////////////////////////////////////
	//
	//	DragDrop.hpp
	//
	enum class DragItemType;
	struct DragStatus;
	struct DroppedFilePath;
	struct DroppedText;

	//////////////////////////////////////////////////////
	//
	//	PowerStatus.hpp
	//
	enum class ACLineStatus;
	enum class BatteryStatus;
	struct PowerStatus;

	//////////////////////////////////////////////////////
	//
	//	AssetHandle.hpp
	//
	template <class Type> class AssetHandle;

	//////////////////////////////////////////////////////
	//
	//	Cursor.hpp
	//
	enum class CursorStyle;

	//////////////////////////////////////////////////////
	//
	//	Key.hpp
	//
	enum class InputDevice : uint8;
	class Key;

	//////////////////////////////////////////////////////
	//
	//	KeyConjunction.hpp
	//
	class KeyConjunction;

	//////////////////////////////////////////////////////
	//
	//	KeyGroup.hpp
	//
	class KeyGroup;

	//////////////////////////////////////////////////////
	//
	//	TextInput.hpp
	//
	enum class TextInputMode;

	//////////////////////////////////////////////////////
	//
	//	Gamepad.hpp
	//
	struct GamepadInfo;

	//////////////////////////////////////////////////////
	//
	//	DeadZone.hpp
	//
	enum class DeadZoneType;
	struct DeadZone;

	//////////////////////////////////////////////////////
	//
	//	JoyCon.hpp
	//
	class JoyCon;

	//////////////////////////////////////////////////////
	//
	//	Audio.hpp
	//
	struct AudioLoopTiming;
	class Audio;

	//////////////////////////////////////////////////////
	//
	//	Vertex2D.hpp
	//
	struct Vertex2D;

	//////////////////////////////////////////////////////
	//
	//	Sprite.hpp
	//
	struct Sprite;

	//////////////////////////////////////////////////////
	//
	//	BlendState.hpp
	//
	enum class Blend : uint8;
	enum class BlendOp : uint8;
	struct BlendState;

	//////////////////////////////////////////////////////
	//
	//	RasterizerState.hpp
	//
	enum class FillMode : uint8;
	enum class CullMode : uint8;
	struct RasterizerState;

	//////////////////////////////////////////////////////
	//
	//	SamplerState.hpp
	//
	enum class TextureFilter : bool;
	enum class TextureAddressMode : uint8;
	struct SamplerState;

	//////////////////////////////////////////////////////
	//
	//	RenderStateBlock2D.hpp
	//
	class RenderStateBlock2D;

	//////////////////////////////////////////////////////
	//
	//	ViewportBlock2D.hpp
	//
	class ViewportBlock2D;

	//////////////////////////////////////////////////////
	//
	//	Transformer2D.hpp
	//
	class Transformer2D;

	//////////////////////////////////////////////////////
	//
	//	Shader.hpp
	//
	enum class ShaderStage;
	struct BindingPoint;

	//////////////////////////////////////////////////////
	//
	//	VertexShader.hpp
	//
	class VertexShader;

	//////////////////////////////////////////////////////
	//
	//	PixelShader.hpp
	//
	class PixelShader;

	//////////////////////////////////////////////////////
	//
	//	ConstantBuffer.hpp
	//
	template <class Type> class ConstantBuffer;

	//////////////////////////////////////////////////////
	//
	//	Graphics.hpp
	//
	struct DisplayMode;
	struct DisplayOutput;

	//////////////////////////////////////////////////////
	//
	//	Texture.hpp
	//
	enum class TextureDesc;
	class Texture;

	//////////////////////////////////////////////////////
	//
	//	TextureRegion.hpp
	//
	struct TextureRegion;

	//////////////////////////////////////////////////////
	//
	//	TexturedCircle.hpp
	//
	struct TexturedCircle;

	//////////////////////////////////////////////////////
	//
	//	TexturedQuad.hpp
	//
	struct TexturedQuad;

	//////////////////////////////////////////////////////
	//
	//	TexturedRoundRect.hpp
	//
	struct TexturedRoundRect;

	//////////////////////////////////////////////////////
	//
	//	DynamicTexture.hpp
	//
	class DynamicTexture;

	//////////////////////////////////////////////////////
	//
	//	RenderTexture.hpp
	//
	class RenderTexture;
  
	//////////////////////////////////////////////////////
	//
	//	OutlineGlyph.hpp
	//
	struct OutlineGlyph;

	//////////////////////////////////////////////////////
	//
	//	Font.hpp
	//
	enum class Typeface;
	enum class FontStyle : uint32;
	struct Glyph;
	class Font;
	class GlyphIterator;
	struct DrawableText;

	//////////////////////////////////////////////////////
	//
	//	Emoji.hpp
	//
	struct Emoji;

	//////////////////////////////////////////////////////
	//
	//	Icon.hpp
	//
	struct Icon;

	//////////////////////////////////////////////////////
	//
	//	TextEditor.hpp
	//
	class TextEditor;

	//////////////////////////////////////////////////////
	//
	//	TextBox.hpp
	//
	class TextBox;

	//////////////////////////////////////////////////////
	//
	//	Effect.hpp
	//
	struct IEffect;
	class Effect;

	//////////////////////////////////////////////////////
	//
	//	Asset.hpp
	//
	struct AssetParameter;
	class IAsset;

	//////////////////////////////////////////////////////
	//
	//	AudioAsset.hpp
	//
	struct AudioAssetData;
	class AudioAsset;

	//////////////////////////////////////////////////////
	//
	//	TextureAsset.hpp
	//
	struct TextureAssetData;
	class TextureAsset;

	//////////////////////////////////////////////////////
	//
	//	FontAsset.hpp
	//
	struct FontAssetData;
	class FontAsset;

	//////////////////////////////////////////////////////
	//
	//	Physics2D.hpp
	//
	struct P2Material;
	struct P2Filter;
	enum class P2ShapeType;
	class P2World;
	class P2Body;
	struct P2Fixture;
	class P2Shape;
	class P2Line;
	class P2LineString;
	class P2Circle;
	class P2Rect;
	class P2Triangle;
	class P2Quad;
	class P2Polygon;
	class P2RevoluteJoint;

	//////////////////////////////////////////////////////
	//
	//	SVM.hpp
	//
	namespace SVM
	{
		template <size_t _Dimensions> struct SupportVector;
		struct SparseSupportVector;
		class Problem;
		class PredictModel;
	}

	//////////////////////////////////////////////////////
	//
	//	Script.hpp
	//
	struct ScriptModuleData;
	template <class Type> struct ScriptFunction;
	class Script;
}
