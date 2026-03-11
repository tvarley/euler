var assert = require('assert');
var solution032 = require('../src/euler/solution032');

describe('Solution032', function() {
  describe('answer', function() {
    it('will answer problem 032', function() {
      assert.equal(solution032.answer(), 45228);
    });
  });
});