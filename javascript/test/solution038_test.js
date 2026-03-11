var assert = require('assert');
var solution038 = require('../src/euler/solution038');

describe('Solution038', function() {
  describe('answer', function() {
    it('will answer problem 038', function() {
      assert.equal(solution038.answer(), 932718654);
    });
  });
});