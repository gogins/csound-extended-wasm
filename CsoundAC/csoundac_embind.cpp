/*

    Copyright (C) 2018 Michael Gogins

    This file is part of csound-extended.

    The Csound Library is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    Csound is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with Csound; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
    02111-1307 USA

    As a special exception, if other files instantiate templates or
    use macros or inline functions from this file, this file does not
    by itself cause the resulting executable or library to be covered
    by the GNU Lesser General Public License. This exception does not
    however invalidate any other reasons why the library or executable
    file might be covered by the GNU Lesser General Public License.
*/
#include <cstdio>
#include <eigen3/Eigen/Dense>
#include <emscripten/bind.h>
#include <fstream>
#include <iostream>
#include <CsoundAC/Silence.hpp>
#include <string>
#include <sstream>

static void hello() {
    csound::System::message("Hello, World, this is CsoundAC!\n");
}

/*
Filling out the Embind definitions is a big job that needs to be kept in order 
and to enable keeping track of work completed. This is done by following the 
order in the Doxygen documentation for the `csound` namespace by structure 
name and method name, and marking finished classes with a // FINISHED comment.

Public data members of csound:: classes must be exposed as Embind properties
with public getter and setter functions, so these must often be added to the 
C++ code.

The order of definitions does not matter, so just keep them in alphabetical 
order.
*/

EMSCRIPTEN_BINDINGS(csoundac) {  
    // FINISHED
    emscripten::class_<csound::Cell, emscripten::base<csound::ScoreNode> >("Cell")
        .constructor<>()
        .property("durationSeconds", &csound::Cell::getDurationSeconds, &csound::Cell::setDurationSeconds)
        .property("importFilename", &csound::Cell::getImportFilename, &csound::Cell::setImportFilename)
        .property("relativeDuration", &csound::Cell::getRelativeDuration, &csound::Cell::setRelativeDuration)
        .property("repeatCount", &csound::Cell::getRepeatCount, &csound::Cell::setRepeatCount)
    ;
    // FINISHED
    emscripten::class_<csound::CellAdd, emscripten::base<csound::Node> >("CellAdd")
        .constructor<>()
        .function("add", &csound::CellAdd::add)
    ;
    // FINISHED
    emscripten::class_<csound::CellChord, emscripten::base<csound::Node> >("CellChord")
        .constructor<>()
        .function("chord", &csound::CellChord::chord)
    ;
    // FINISHED
    emscripten::class_<csound::CellMultiply, emscripten::base<csound::Node> >("CellMultiply")
        .constructor<>()
        .function("multiply", &csound::CellChord::chord)
    ;
    // FINISHED
    emscripten::class_<csound::CellRandom, emscripten::base<csound::Random> >("CellRandom")
        .constructor<>()
        .function("random", &csound::CellRandom::random)
    ;
    // FINISHED
    emscripten::class_<csound::CellReflect, emscripten::base<csound::Node> >("CellReflect")
        .constructor<>()
        .function("reflect", &csound::CellReflect::reflect)
    ;
    // FINISHED
    emscripten::class_<csound::CellRemove, emscripten::base<csound::Node> >("CellRemove")
        .constructor<>()
        .function("remove", &csound::CellRemove::remove)
    ;
    // FINISHED
    emscripten::class_<csound::CellRepeat, emscripten::base<csound::Node> >("CellRepeat")
        .constructor<>()
        .function("repeat", &csound::CellRepeat::repeat)
    ;
    // FINISHED
    emscripten::class_<csound::CellSelect, emscripten::base<csound::Node> >("CellSelect")
        .constructor<>()
        .function("select", &csound::CellSelect::select)
    ;
    // FINISHED
    emscripten::class_<csound::CellShuffle, emscripten::base<csound::Random> >("CellShuffle")
        .constructor<>()
        .function("shuffle", &csound::CellShuffle::shuffle)
    ;
    //~ // Can't seem to do scoped enums.
    //~ emscripten::enum_<csound::Chord::CHORD_DIMENSION>("CHORD_DIMENSION")
        //~ .value("PITCH", CHORD_DIMENSION::PITCH)
        //~ .value("DURATION", CHORD_DIMENSION::DURATION)
        //~ .value("LOUDNESS", CHORD_DIMENSION::LOUDNESS)
        //~ .value("INSTRUMENT", CHORD_DIMENSION::INSTRUMENT)
        //~ .value("PAN", CHORD_DIMENSION::PAN)
        //~ .value("COUNT", CHORD_DIMENSION::COUNT)
    //~ ;
    emscripten::function("euclidean", &csound::euclidean);
    emscripten::function("factorial", &csound::factorial);
    emscripten::function("midpoint", &csound::midpoint);
    emscripten::function("EPSILON", &csound::EPSILON);
    emscripten::function("epsilonFactor", &csound::epsilonFactor);
    emscripten::function("eq_epsilon", &csound::eq_epsilon);
    emscripten::function("gt_epsilon", &csound::gt_epsilon);
    emscripten::function("lt_epsilon", &csound::lt_epsilon);
    emscripten::function("ge_epsilon", &csound::ge_epsilon);
    emscripten::function("le_epsilon", &csound::le_epsilon);
    emscripten::function("OCTAVE", &csound::OCTAVE);
    emscripten::function("MIDDLE_C", &csound::MIDDLE_C);
    emscripten::function("C4", &csound::C4);
    emscripten::function("T", &csound::T);
    emscripten::function("I", &csound::I);
    emscripten::function("modulo", &csound::modulo);
    emscripten::function("epc", &csound::epc);
    emscripten::function("pitchClassForName", &csound::pitchClassForName);
    emscripten::function("nameForPitchClass", &csound::nameForPitchClass);
    emscripten::function("nameForChord", &csound::nameForChord);
    emscripten::function("chordForName", &csound::chordForName);
    emscripten::function("nameForScale", &csound::nameForScale);
    emscripten::function("scaleForName", &csound::scaleForName);
    emscripten::function("add_chord", &csound::add_chord);
    emscripten::function("add_scale", &csound::add_scale);
    emscripten::function("iterator", &csound::iterator);
    emscripten::function("next", &csound::next);
    emscripten::function("operator==", &csound::operator==);
    emscripten::function("operator<", emscripten::select_overload<bool(const csound::Chord&,const csound::Chord&)>(&csound::operator<));
    emscripten::function("operator<=", &csound::operator<=);
    emscripten::function("operator>", &csound::operator>);
    emscripten::function("operator>=", &csound::operator>=);
    emscripten::function("voiceleading", &csound::voiceleading);
    emscripten::function("parallelFifth", &csound::parallelFifth);
    emscripten::function("voiceleadingSmoothness", &csound::voiceleadingSmoothness);
    emscripten::function("voiceleadingSmoother", &csound::voiceleadingSmoother);
    emscripten::function("voiceleadingSimpler", &csound::voiceleadingSimpler);
    emscripten::function("voiceleadingCloser", &csound::voiceleadingCloser);
    emscripten::function("voiceleadingClosestRange", &csound::voiceleadingClosestRange);
    emscripten::function("closestPitch", &csound::closestPitch);
    emscripten::function("conformToPitchClassSet", &csound::conformToPitchClassSet);
    emscripten::function("conformToChord", &csound::conformToChord);
    emscripten::function("insert", &csound::insert);
    emscripten::function("slice", &csound::slice);
    emscripten::function("apply", &csound::apply);
    emscripten::function("gather", &csound::gather);
    emscripten::function("octavewiseRevoicings", &csound::octavewiseRevoicings);
    emscripten::function("octavewiseRevoicing", &csound::octavewiseRevoicing);
    emscripten::function("indexForOctavewiseRevoicing", &csound::indexForOctavewiseRevoicing);
    emscripten::function("scale", &csound::scale);
    emscripten::function("chord", &csound::chord);
    emscripten::function("transpose_degrees", &csound::transpose_degrees);
    emscripten::register_vector<csound::Chord>("ChordVector");
    emscripten::register_vector<csound::Scale>("ScaleVector");
    emscripten::register_vector<double>("DoubleVector");
    emscripten::register_map<std::string,std::string>("StringToStringMap");
    emscripten::class_<csound::Chord>("Chord")
        .constructor<>()
        .constructor<csound::Chord>()
        // May need to rewrite with pointers.
        //.function("a", &csound::Chord::a)
        .function("ceiling", &csound::Chord::ceiling)
        .function("contains", &csound::Chord::contains)
        .function("count", &csound::Chord::count)
        .function("cycle", &csound::Chord::cycle)
        .function("distanceToOrigin", &csound::Chord::distanceToOrigin)
        .function("distanceToUnisonDiagonal", &csound::Chord::distanceToUnisonDiagonal)
        .function("eI", &csound::Chord::eI)
        .function("eO", &csound::Chord::eO)
        .function("eOP", &csound::Chord::eOP)
        .function("eOPI", &csound::Chord::eOPI)
        .function("eOPT", &csound::Chord::eOPT)
        .function("eOPTI", &csound::Chord::eOPTI)
        .function("eOPTT", &csound::Chord::eOPTT)
        .function("eOPTTI", &csound::Chord::eOPTTI)
        .function("eP", &csound::Chord::eP)
        .function("epcs", &csound::Chord::epcs)
        .function("equals", &csound::Chord::equals)
        .function("eR", &csound::Chord::eR)
        .function("eRP", &csound::Chord::eRP)
        .function("eRPI", &csound::Chord::eRPI)
        .function("eRPT", &csound::Chord::eRPT)
        .function("eRPTI", &csound::Chord::eRPTI)
        .function("eRPTT", &csound::Chord::eRPTT)
        .function("eRPTTI", &csound::Chord::eRPTTI)
        .function("et", &csound::Chord::et)
        .function("eT", &csound::Chord::eT)
        .function("eTT", &csound::Chord::eTT)
        .function("eV", &csound::Chord::eV)
        .function("floor", &csound::Chord::floor)
        .function("fromString", &csound::Chord::fromString)
        .function("getDuration", &csound::Chord::getDuration)
        .function("getInstrument", &csound::Chord::getInstrument)
        .function("getLoudness", &csound::Chord::getLoudness)
        .function("getPan", &csound::Chord::getPan)
        .function("getPitch", &csound::Chord::getPitch)
        .function("I", &csound::Chord::I)
        .function("Iform", &csound::Chord::Iform)
        .function("information", &csound::Chord::information)
        .function("iseI", &csound::Chord::iseI)
        .function("iseI_chord", &csound::Chord::iseI_chord, emscripten::allow_raw_pointers())
        .function("iseOP", &csound::Chord::iseOP)
        .function("iseOPI", &csound::Chord::iseOPI)
        .function("iseOPT", &csound::Chord::iseOPT)
        .function("iseOPTI", &csound::Chord::iseOPTI)
        .function("iseOPTT", &csound::Chord::iseOPTT)
        .function("iseOPTTI", &csound::Chord::iseOPTTI)
        .function("iseP", &csound::Chord::iseP)
        .function("isepcs", &csound::Chord::isepcs)
        .function("iseR", &csound::Chord::iseR)
        .function("iseRP", &csound::Chord::iseRP)
        .function("iseRPI", &csound::Chord::iseRPI)
        .function("iseRPT", &csound::Chord::iseRPT)
        .function("iseRPTI", &csound::Chord::iseRPTI)
        .function("iseRPTT", &csound::Chord::iseRPTT)
        .function("iseRPTTI", &csound::Chord::iseRPTTI)
        .function("iset", &csound::Chord::iset)
        .function("iseT", &csound::Chord::iseT)
        .function("iseTT", &csound::Chord::iseTT)
        .function("iseV", &csound::Chord::iseV)
        .function("K", &csound::Chord::K)
        .function("layer", &csound::Chord::layer)
        .function("max", &csound::Chord::max)
        .function("maximallyEven", &csound::Chord::maximallyEven)
        .function("maximumInterval", &csound::Chord::maximumInterval)
        .function("min", &csound::Chord::min)
        .function("minimumInterval", &csound::Chord::minimumInterval)
        .function("move", &csound::Chord::move)
        .function("name", &csound::Chord::name)
        .function("note", &csound::Chord::note)
        .function("notes", &csound::Chord::notes)
        .function("nrD", &csound::Chord::nrD)
        .function("nrH", &csound::Chord::nrH)
        .function("nrL", &csound::Chord::nrL)
        .function("nrN", &csound::Chord::nrN)
        .function("nrP", &csound::Chord::nrP)
        .function("nrR", &csound::Chord::nrR)
        .function("nrS", &csound::Chord::iseV)
        .function("operator=", emscripten::select_overload<csound::Chord &(const csound::Chord &)>(&csound::Chord::operator=))
        .function("origin", &csound::Chord::origin)
        .function("permutations", &csound::Chord::permutations)
        .function("Q", &csound::Chord::Q)
        .function("resize", &csound::Chord::resize)
        .function("setDuration", &csound::Chord::setDuration)
        .function("setInstrument", &csound::Chord::setInstrument)
        .function("setLoudness", &csound::Chord::setLoudness)
        .function("setPan", &csound::Chord::setPan)
        .function("setPitch", &csound::Chord::setPitch)
        .function("T", &csound::Chord::T)
        .function("T_voiceleading", &csound::Chord::T_voiceleading)
        .function("Tform", &csound::Chord::Tform)
        .function("toScore", &csound::Chord::toScore)
        .function("toString", &csound::Chord::toString)
        .function("v", &csound::Chord::v)
        .function("voiceleading", &csound::Chord::voiceleading)
        .function("voices", &csound::Chord::voices)
    ;
    // FINISHED
    emscripten::class_<csound::ChordLindenmayer, emscripten::base<csound::VoiceleadingNode> >("ChordLindenmayer")
        .constructor<>()
        .function("addRule", &csound::ChordLindenmayer::addRule)
        .function("createRotation", &csound::ChordLindenmayer::createRotation)
        // Can't do this by returning in a reference argument.
        // .function("equivalence", &csound::ChordLindenmayer::equivalence)
        .function("fixStatus", &csound::ChordLindenmayer::fixStatus)
        .function("generateLindenmayerSystem", &csound::ChordLindenmayer::generateLindenmayerSystem)
        .function("getAngle", &csound::ChordLindenmayer::getAngle)
        .function("getAxiom", &csound::ChordLindenmayer::getAxiom)
        .function("getDimension", &csound::ChordLindenmayer::getDimension)
        .function("getIterationCount", &csound::ChordLindenmayer::getIterationCount)
        .function("getReplacement", &csound::ChordLindenmayer::getReplacement)
        .function("initialize", &csound::ChordLindenmayer::initialize)
        .function("interpret", &csound::ChordLindenmayer::interpret)
        // Can't do this by returning a value in a reference argument.
        // .function("parseCommand", &csound::ChordLindenmayer::parseCommand)
        .function("setAngle", &csound::ChordLindenmayer::setAngle)
        .function("setAxiom", &csound::ChordLindenmayer::setAxiom)
        .function("setIterationCount", &csound::ChordLindenmayer::setIterationCount)
        .function("tieOverlappingNotes", &csound::ChordLindenmayer::tieOverlappingNotes)
        .function("writeScore", &csound::ChordLindenmayer::writeScore)
    ;
    // FINISHED
    emscripten::class_<csound::ChordScore, emscripten::base<csound::Score> >("ChordScore")
        .constructor<>()
        .function("conformToChords", &csound::ChordScore::conformToChords)
        .function("getChord", &csound::ChordScore::getChord, emscripten::allow_raw_pointers())
        .function("insertChord", &csound::ChordScore::insertChord)
    ;
    emscripten::class_<csound::ChordSpaceGroup>("ChordSpaceGroup")
        .constructor<>()
        .function("createChordSpaceGroup", &csound::ChordSpaceGroup::createChordSpaceGroup)
        .function("createFilename", &csound::ChordSpaceGroup::createFilename)
        .function("fromChord", &csound::ChordSpaceGroup::fromChord)
        .function("initialize", &csound::ChordSpaceGroup::initialize)
        .function("list", &csound::ChordSpaceGroup::list)
        .function("load", &csound::ChordSpaceGroup::load)
        .function("preinitialize", &csound::ChordSpaceGroup::preinitialize)
        .function("save", &csound::ChordSpaceGroup::save)
        .function("toChord", &csound::ChordSpaceGroup::toChord)
    ;
    // FINISHED
    emscripten::function("operator<", emscripten::select_overload<bool(const csound::Event&,const csound::Event&)>(&csound::operator<));
    emscripten::class_<csound::Event, emscripten::base<Eigen::VectorXd> >("Event")
        .constructor<>()
        .constructor<const csound::Event&>()
        .constructor<std::string>()
        .constructor<const Eigen::VectorXd&>()
        .constructor<double, double, double, double, double, double, double, double, double, double, double>()
        .constructor<std::vector<double> >()
        .function("clearProperties", &csound::Event::clearProperties)
        .function("conformToPitchClassSet", &csound::Event::conformToPitchClassSet)
        .function("createNoteOffEvent", &csound::Event::createNoteOffEvent)
        .function("dump", &csound::Event::dump)
        .function("getAmplitude", &csound::Event::getAmplitude)
        .function("getChannel", &csound::Event::getChannel)
        .function("getDepth", &csound::Event::getDepth)
        .function("getDuration", &csound::Event::getDuration)
        .function("getFrequency", &csound::Event::getFrequency)
        .function("getGain", &csound::Event::getGain)
        .function("getHeight", &csound::Event::getHeight)
        .function("getInstrument", &csound::Event::getInstrument)
        .function("getKey", &csound::Event::getKey)
        .function("getKey_tempered", &csound::Event::getKey_tempered)
        .function("getKeyNumber", &csound::Event::getKeyNumber)
        .function("getLeftGain", &csound::Event::getLeftGain)
        .function("getMidiStatus", &csound::Event::getMidiStatus)
        .function("getKeyNumber", &csound::Event::getKeyNumber)
        .function("getOffTime", &csound::Event::getOffTime)
        .function("getPan", &csound::Event::getPan)
        .function("getPhase", &csound::Event::getPhase)
        .function("getPitches", &csound::Event::getPitches)
        .function("getProperties", &csound::Event::getProperties)
        .function("getProperty", &csound::Event::getProperty)
        .function("getRightGain", &csound::Event::getRightGain)
        .function("getStatus", &csound::Event::getStatus)
        .function("getStatusNumber", &csound::Event::getStatusNumber)
        .function("getTime", &csound::Event::getTime)
        .function("getVelocity", &csound::Event::getVelocity)
        .function("getVelocityNumber", &csound::Event::getVelocityNumber)
        .function("initialize", &csound::Event::initialize)
        .function("isMatchingEvent", &csound::Event::isMatchingEvent)
        .function("isMatchingNoteOff", &csound::Event::isMatchingNoteOff)
        .function("isMidiEvent", &csound::Event::isMidiEvent)
        .function("isNote", &csound::Event::isNote)
        .function("isNoteOff", &csound::Event::isNoteOff)
        .function("isNoteOn", &csound::Event::isNoteOn)
        .function("operator=", emscripten::select_overload<csound::Event&(const csound::Event&)>(&csound::Event::operator=))
        .function("removeProperty", &csound::Event::removeProperty)
        .function("set", &csound::Event::set)
        .function("setAmplitude", &csound::Event::setAmplitude)
        .function("setDepth", &csound::Event::setDepth)
        .function("setDuration", &csound::Event::setDuration)
        .function("setFrequency", &csound::Event::setFrequency)
        .function("setHeight", &csound::Event::setHeight)
        .function("setInstrument", &csound::Event::setInstrument)
        .function("setKey", &csound::Event::setKey)
        .function("setOffTime", &csound::Event::setOffTime)
        .function("setPan", &csound::Event::setPan)
        .function("setPhase", &csound::Event::setPhase)
        .function("setPitches", &csound::Event::setPitches)
        .function("setProperty", &csound::Event::setProperty)
        .function("setStatus", &csound::Event::setStatus)
        .function("setTime", &csound::Event::setTime)
        .function("setVelocity", &csound::Event::setVelocity)
        .function("temper", &csound::Event::temper)
        .function("toCsoundIStatement", &csound::Event::toCsoundIStatement)
        .function("toCsoundIStatementHeld", &csound::Event::toCsoundIStatementHeld)
        .function("toCsoundIStatementRelease", &csound::Event::toCsoundIStatementRelease)
        .function("toString", &csound::Event::toString)
    ;
    emscripten::function("hello", &hello);
    // FINISHED
    emscripten::class_<csound::Node>("Node")
        .constructor<>()
        .function("addChild", &csound::Node::addChild, emscripten::allow_raw_pointers())
        .function("childCount", &csound::Node::childCount)
        .function("clear", &csound::Node::clear)
        .function("createTransform", &csound::Node::createTransform)
        .function("element", &csound::Node::element)
        .function("generate", &csound::Node::generate)
        .function("getChild", &csound::Node::getChild, emscripten::allow_raw_pointers())
        .function("getLocalCoordinates", &csound::Node::getLocalCoordinates)
        .function("setElement", &csound::Node::setElement)
        .function("transform", &csound::Node::transform)
        .function("traverse", &csound::Node::traverse)
    ;
    // FINISHED
    emscripten::class_<csound::Random, emscripten::base<csound::Node> >("Random")
        .constructor<>()
       .function("createDistribution", &csound::Random::createDistribution)
       .function("getRandomCoordinates", &csound::Random::getRandomCoordinates)
       .function("sample", &csound::Random::sample)
       .function("seed", &csound::Random::seed)
    ;
    // FINISHED
    emscripten::class_<csound::Scale>("Scale")
        .constructor<>()
        .constructor<std::string>()
        .constructor<std::string, const csound::Chord&>()
        .function("chord", &csound::Scale::chord)
        .function("operator=", &csound::Scale::operator=)
        .function("getTypeName", &csound::Scale::getTypeName)
        .function("modulations", &csound::Scale::modulations)
        .function("modulations_for_scale_types", &csound::Scale::modulations_for_scale_types)
        .function("relative_tonicizations", &csound::Scale::relative_tonicizations)
        .function("relative_tonicizations_for_scale_types", &csound::Scale::relative_tonicizations_for_scale_types)
        .function("secondary", &csound::Scale::secondary)
        .function("semitones_for_degree", &csound::Scale::semitones_for_degree)
        .function("tonic", &csound::Scale::tonic)
        .function("tonicizations", &csound::Scale::tonicizations)
        .function("transpose", &csound::Scale::transpose)
        .function("transpose_degrees", &csound::Scale::transpose_degrees)
        .function("transpose_to_degree", &csound::Scale::transpose_to_degree)
    ;
    emscripten::class_<csound::Score>("Score")
        .constructor<>()
    ;
    // FINISHED
    emscripten::class_<csound::ScoreNode, emscripten::base<csound::Node> >("ScoreNode")
        .constructor<>()
        .function("getScore", &csound::ScoreNode::getScore, emscripten::allow_raw_pointers())
    ;
    emscripten::class_<Eigen::VectorXd>("VectorXd")
        .constructor<>()
    ;
 
}