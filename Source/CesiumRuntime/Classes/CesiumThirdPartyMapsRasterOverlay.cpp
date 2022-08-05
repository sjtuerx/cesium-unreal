// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#include "CesiumThirdPartyMapsRasterOverlay.h"
#include "ThirdPartyMapsRasterOverlay.h"
#include "Cesium3DTilesSelection/Tileset.h"

std::unique_ptr<Cesium3DTilesSelection::RasterOverlay>
UCesiumThirdPartyMapsRasterOverlay::CreateOverlay(
    const Cesium3DTilesSelection::RasterOverlayOptions& options) {
  std::string mapStyle;

  switch (this->MapStyle) {
  case EThirdPartyMapsStyle::Aerial:
    mapStyle = Cesium3DTilesSelection::ThirdPartyMapsStyle::AERIAL;
    break;
  case EThirdPartyMapsStyle::AerialWithLabelsOnDemand:
    mapStyle =
        Cesium3DTilesSelection::ThirdPartyMapsStyle::AERIAL_WITH_LABELS_ON_DEMAND;
    break;
  case EThirdPartyMapsStyle::RoadOnDemand:
    mapStyle = Cesium3DTilesSelection::ThirdPartyMapsStyle::ROAD_ON_DEMAND;
    break;
  case EThirdPartyMapsStyle::CanvasDark:
    mapStyle = Cesium3DTilesSelection::ThirdPartyMapsStyle::CANVAS_DARK;
    break;
  case EThirdPartyMapsStyle::CanvasLight:
    mapStyle = Cesium3DTilesSelection::ThirdPartyMapsStyle::CANVAS_LIGHT;
    break;
  case EThirdPartyMapsStyle::CanvasGray:
    mapStyle = Cesium3DTilesSelection::ThirdPartyMapsStyle::CANVAS_GRAY;
    break;
  case EThirdPartyMapsStyle::OrdnanceSurvey:
    mapStyle = Cesium3DTilesSelection::ThirdPartyMapsStyle::ORDNANCE_SURVEY;
    break;
  case EThirdPartyMapsStyle::CollinsBart:
    mapStyle = Cesium3DTilesSelection::ThirdPartyMapsStyle::COLLINS_BART;
    break;
  }

  return std::make_unique<Cesium3DTilesSelection::ThirdPartyMapsRasterOverlay>(
      TCHAR_TO_UTF8(*this->MaterialLayerKey),
      "https://dev.virtualearth.net",
      TCHAR_TO_UTF8(*this->ThirdPartyMapsKey),
      mapStyle,
      "",
      CesiumGeospatial::Ellipsoid::WGS84,
      options);
  return nullptr;
}
